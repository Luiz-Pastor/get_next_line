/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 07:54:18 by lpastor-          #+#    #+#             */
/*   Updated: 2023/09/25 14:26:06 by lpastor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"
#include "colores.h"

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
	res[index_res] = '\0';
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
	{
		res[index] = data[index];
		index++;
	}
	res[index] = '\0';
	return (res);
}

char	*remove_line(char *data)
{
	size_t	index;
	size_t	length;
	size_t	start;
	char	*res;

	index = 0;
	if (!data)
		return (NULL);
	while (data[index] && data[index] != '\n')
		index++;
	if (!data[index])
		return (NULL);
	index++;
	length = index;
	start = index;
	while (data[length])
		length++;
	res = (char *) malloc(length);
	if (!res)
		return (res);
	while (index < length)
	{
		res[index - start] = data[index];
		index++;
	}
	res[index - start] = '\0';
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*data;
	char		*memory;
	char		*temp;
	size_t		length;

	if (fd < 0 || read(fd, 0, 0))
		return (NULL);

	memory = find_ch(data, '\n');
	if (memory)
	{
		data = remove_line(data);
		if (!data)
			return (data);
		//printf("%s=========DATA=========%s\n%s\n%s======================%s\n", COLOR_CYAN, COLOR_RESET, data, COLOR_CYAN, COLOR_RESET);
		return (memory);
	}
	while (1)
	{
		/*temp = (char *) malloc(BUFFER_SIZE + 1);
		if (!temp)
			return (NULL);
		length = read(fd, temp, BUFFER_SIZE);
		temp[length] = '\0';
		data = add_data(data, temp);
		if (!data)
			return (NULL);
		if (length != BUFFER_SIZE)
		{
			printf("%sF%s\n", COLOR_RED, COLOR_RESET);
			printf("%s=========DATA=========%s\n%s\n%s======================%s\n", COLOR_CYAN, COLOR_RESET, data, COLOR_CYAN, COLOR_RESET);
			memory = find_ch(data, '\n');
			if (memory)
			{
				data = remove_line(data);
				if (!data)
					return (data);
				return (memory);
			}
			else
				return (data);			
		}*/
		temp = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!temp)
			return (NULL);
		length = read(fd, temp, BUFFER_SIZE);
		temp[length] = '\0';
		data = add_data(data, temp);
		// printf("# %zu\n", length);
		//printf("%s========LEIDO:========%s\n%s\n%s======================%s\n", COLOR_CYAN, COLOR_RESET, temp, COLOR_CYAN, COLOR_RESET);
		//printf("%s=========DATA=========%s\n%s\n%s======================%s\n", COLOR_CYAN, COLOR_RESET, data, COLOR_CYAN, COLOR_RESET);
		memory = find_ch(data, '\n');
		//printf("%s=========LINE=========%s\n%s\n%s======================%s\n", COLOR_LIGHTGREEN, COLOR_RESET, memory, COLOR_LIGHTGREEN, COLOR_RESET);
		if (memory)
			data = remove_line(data);
		//printf("%s=========DATA=========%s\n%s\n%s======================%s\n", COLOR_LIGHTGREEN, COLOR_RESET, data, COLOR_LIGHTGREEN, COLOR_RESET);
		if (memory)
			break;
		//printf("\n\n");
	}
	return (memory);
	// return (NULL);
}
