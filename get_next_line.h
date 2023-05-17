/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatta <amatta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:50:01 by amatta            #+#    #+#             */
/*   Updated: 2023/05/17 16:53:42 by amatta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

char	*get_next_line(int fd);
char	*ft_read_line(char *backup, int fd);
char	*ft_get_line(char *backup);
char	*ft_newline(char *backup);
size_t	ft_strlen(char *str);
char	*ft_strchr_nl(char *str);
char	*ft_strjoin(char *line, char *buff);

#endif
