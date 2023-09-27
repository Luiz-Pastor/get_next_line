/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 08:02:16 by lpastor-          #+#    #+#             */
/*   Updated: 2023/09/27 10:11:14 by lpastor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	gnl_strlen(char *str)
{
	size_t	index;

	index = 0;
	if (!str)
		return (0);
	while (str[index])
		index++;
	return (index);
}

char	*gnl_cpy(char *data)
{
	size_t	index;
	char	*cpy;

	index = 0;
	if (!data)
		return (NULL);
	cpy = (char *) malloc(gnl_strlen(data) + 1);
	if (!cpy)
		return (NULL);
	while (data[index])
	{
		cpy[index] = data[index];
		index++;
	}
	cpy[index] = '\0';
	return (cpy);
}

int	gnl_find_ch(char *data, char ch)
{
	size_t	index;

	index = 0;
	if (!data)
		return (0);
	while (data[index] && data[index] != ch)
		index++;
	if (data[index] == ch)
		return (1);
	return (0);
}

void	*gnl_free(void **memory)
{
	if (!memory || !(*memory))
		return (NULL);
	free(*memory);
	*memory = NULL;
	return (NULL);
}
