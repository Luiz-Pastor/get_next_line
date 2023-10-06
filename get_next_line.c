/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 07:54:18 by lpastor-          #+#    #+#             */
/*   Updated: 2023/10/06 12:39:53 by lpastor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*add_line(char *data, char *add)
{
	char	*new;
	size_t	index_in;
	size_t	index_new;

	index_in = 0;
	index_new = 0;
	new = (char *) malloc(gnl_strlen(data) + gnl_strlen(add) + 1);
	if (!new)
	{
		gnl_free((void**)&add);
		return (gnl_free((void**)&data));
	}
	while (data && data[index_in])
		new[index_new++] = data[index_in++];
	index_in = 0;
	while (add[index_in])
		new[index_new++] = add[index_in++];
	new[index_new] = '\0';
	if (data)
		gnl_free((void**)&data);
	gnl_free((void**)&add);
	return (new);
}

static char	*get_line(char *data)
{
	char	*line;
	size_t	index;

	index = 1;
	if (!data)
		return (NULL);
	while (data[index - 1] && data[index - 1] != '\n')
		index++;
	if (!data[index - 1])
		return (NULL);
	line = (char *) malloc(index + 1);
	if (!line)
		return (NULL);
	index = 0;
	while (data[index] && data[index] != '\n')
	{
		line[index] = data[index];
		index++;
	}
	line[index] = '\n';
	line[index + 1] = '\0';
	return (line);
}

static char	*delete_line(char *data)
{
	char	*new;
	size_t	index_data;
	size_t	index_new;
	size_t	count;

	index_data = 1;
	index_new = 0;
	if (!data)
		return (NULL);
	while (data[index_data - 1] && data[index_data - 1] != '\n')
		index_data++;
	if (!data[index_data - 1])
		return (data);
	count = gnl_strlen(data) - index_data;
	if (!count)
		return (gnl_free((void**)&data));
	new = (char *) malloc(count + 1);
	if (!new)
		return (gnl_free((void**)&data));
	while (data[index_data])
		new[index_new++] = data[index_data++];
	new[index_new] = '\0';
	gnl_free((void**)&data);
	return (new);
}

static char	*read_file(int fd, char **data)
{
	char	*temp;
	size_t	length;

	while (1)
	{
		temp = (char *) malloc(BUFFER_SIZE + 1);
		if (!temp)
			return (gnl_free((void**)data));
		length = read(fd, temp, BUFFER_SIZE);
		if (length == 0)
		{
			gnl_free((void**)&temp);
			return (*data);
		}
		if (length < 0)
			return (gnl_free((void**)temp), gnl_free((void **)data));
		temp[length] = '\0';
		*data = add_line(*data, temp);
		if (!*data)
			return (NULL);
		if (gnl_find_ch(*data, '\n'))
			return (*data);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*data;
	char		*line;

	if (fd < 0 || read(fd, 0, 0) || BUFFER_SIZE < 1)
		return (gnl_free((void **)&data));
	if (gnl_find_ch(data, '\n'))
	{
		line = get_line(data);
		if (!line && data)
			return (gnl_free((void **)&data));
		data = delete_line(data);
		return (line);
	}
	data = read_file(fd, &data);
	if (!data)
		return (NULL);
	if (gnl_find_ch(data, '\n'))
	{
		line = get_line(data);
		if (!line && data)
			return (gnl_free((void **)&data));
		data = delete_line(data);
		return (line);
	}
	line = gnl_cpy(data);
	gnl_free((void **)&data);
	return (line);
}
