/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 07:54:18 by lpastor-          #+#    #+#             */
/*   Updated: 2023/09/27 11:03:13 by lpastor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*add_line(char *data, char *add)
{
	char	*new;
	size_t	index_in;
	size_t	index_new;

	index_in = 0;
	index_new = 0;
	new = (char *) malloc(gnl_strlen(data) + gnl_strlen(add) + 1);
	if (!new)
		return (NULL);
	while (data && data[index_in])
		new[index_new++] = data[index_in++];
	index_in = 0;
	while (add[index_in])
		new[index_new++] = add[index_in++];
	new[index_new] = '\0';
	if (data)
		free(data);
	free(add);
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
		return (gnl_free((void **)&data));
	new = (char *) malloc(count + 1);
	if (!new)
		return (NULL);
	while (data[index_data])
		new[index_new++] = data[index_data++];
	new[index_new] = '\0';
	free(data);
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
			return (NULL);
		length = read(fd, temp, BUFFER_SIZE);
		temp[length] = '\0';
		if (length == 0)
		{
			free(temp);
			return (*data);
		}
		if (length < 0)
			return (gnl_free((void **)data));
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
	static char	*data[MAX_FD];
	char		*line;

	if (fd < 0 || read(fd, 0, 0))
		return (gnl_free((void **)&data[fd]));
	if (gnl_find_ch(data[fd], '\n'))
	{
		line = get_line(data[fd]);
		data[fd] = delete_line(data[fd]);
		return (line);
	}
	data[fd] = read_file(fd, &data[fd]);
	if (gnl_find_ch(data[fd], '\n'))
	{
		line = get_line(data[fd]);
		data[fd] = delete_line(data[fd]);
		return (line);
	}
	line = gnl_cpy(data[fd]);
	if (data[fd])
		gnl_free((void **)&data[fd]);
	return (line);
}
