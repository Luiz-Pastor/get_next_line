/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 07:54:34 by lpastor-          #+#    #+#             */
/*   Updated: 2023/10/07 23:14:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

size_t	gnl_strlen(char *str);
char	*gnl_cpy(char *data);
int		gnl_find_ch(char *data, char ch);
char	*add_line(char *data, char *add);
void	*gnl_free(void **memory);

char	*get_next_line(int fd);

#endif