/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 12:35:02 by jtaravel          #+#    #+#             */
/*   Updated: 2022/02/01 02:34:50 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 500

# endif

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "so_long.h"

char	*ft_strchr(const char *s, int c);
char	*get_next_line(int fd);
char	*ft_get_line(char *str);
char	*ft_next_line(char *str);
char	*ft_read(char *tmp, int fd);
char	*ft_strjoin(char *s1, char *s2);
void	ft_bzero(void *s, size_t n);

#endif
