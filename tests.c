/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:49:15 by lpastor-          #+#    #+#             */
/*   Updated: 2023/09/26 22:15:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

#define FILE "files/read_error.txt"

int	main(void)
{
	int fd;
	int check;
	char *line;

	fd = open(FILE, O_RDONLY);

	check = 1;
	while (check)
	{
		line = get_next_line(fd);
		printf("%s", line);
		if (line)
			free(line);
		else
			check = 0;
	}

	return (0);
}
