/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 07:54:18 by lpastor-          #+#    #+#             */
/*   Updated: 2023/09/22 11:14:47 by lpastor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

char	*add_data(char *data, char *input)
{
	size_t	index_data;
	size_t	index_input;
	size_t	index_res;
	char	*res;

	index_data = 0;
	index_input = 0;
	index_res = 0;

	while (data && data[index_data])
		index_data++;
	while (input[index_input])
		index_input++;
	res = (char *) malloc(index_data + index_input + 1);
	if (!res)
		return (NULL);
	index_data = 0;
	index_input = 0;
	while (data && data[index_data])
		res[index_res++] = data[index_data++];
	while (input[index_input])
		res[index_res++] = input[index_input++];
	free(data);
	free(input);
	return (res);
}

char	*find_ch(char *data, char ch)
{
	size_t	length;
	size_t	index;
	char	*res;
	
	index = 0;
	length = 0;
	if (!data)
		return (NULL);
	while (data[length] && data[length] != ch)
		length++;
	if (!data[length])
		return (NULL);
	res = (char *) malloc(length + 1);
	if (!res)
		return (NULL);
	while (data[index] && index < length && data[index] != ch)
		res[index] = data[index];
	res[index] = '\0';
	return (res);
}

/*static char	*search_saved(char *data)
{
	size_t	index;
	char	*memory;

	index = 0;
	if (!data)
		return (NULL);
	while (data[index] && data[index] != '\0')
		index++;
	if (!data[index])
		return (NULL);
	memory = (char *) malloc(index + 1);
	if (!memory)
		return (NULL);
	index = 0;
	while (data[index])
	{
		memory[index] = data[index];
		index++;
	}
	return (memory);
}*/

char	*get_next_line(int fd)
{
	/*static char	*data;
	char		*memory;*/
	char		*temp;
	size_t		length;

	if (fd < 0 || read(fd, 0, 0))
		return (NULL);

/*	memory = search_saved(data);
	if (memory)
		return (memory);*/

	printf("BUFFER_SIZE: %d\n", BUFFER_SIZE);
	temp = (char *) malloc(BUFFER_SIZE + 1);
	if (!temp)
		return (NULL);
	length = read(fd, temp, BUFFER_SIZE);
	temp[length] = '\0';
	printf("# %zu\n", length);
	printf(">>> %s\n", temp);
	/*data = add_data(data, temp);
	if (!data)
		return (NULL);
	memory = find_ch(data, '\n');*/
//		if (memory)
//			break;

	//return (memory);
	return (NULL);
}
