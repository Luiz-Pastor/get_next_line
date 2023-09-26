/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 07:54:34 by lpastor-          #+#    #+#             */
/*   Updated: 2023/09/26 11:50:06 by lpastor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>

size_t	gnl_strlen(char *str);
char	*gnl_cpy(char *data);
int		gnl_find_ch(char *data, char ch);
void	*gnl_free(void **memory);

char	*get_next_line(int fd);

#endif