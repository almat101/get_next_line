/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatta <amatta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:50:14 by amatta            #+#    #+#             */
/*   Updated: 2023/05/17 18:23:27 by amatta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_line(char *backup, int fd)
{
	char	*buffer;
	int		rd;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	rd = 1;
	while (!ft_strchr_nl(backup) && rd != 0)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[rd] = 0;
		backup = ft_strjoin(backup, buffer);
	}
	free (buffer);
	return (backup);
}

char	*ft_get_line(char *backup)
{
	char	*str;
	int		i;

	i = 0;
	if (!backup[i])
		return (NULL);
	while (backup[i] && backup[i] != 10)
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (backup[i] && backup[i] != 10)
	{
		str[i] = backup[i];
		i++;
	}
	if (backup[i] == 10)
	{
		str[i] = backup[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	backup = ft_read_line(backup, fd);
	if (!backup)
		return (NULL);
	line = ft_get_line(backup);
	backup = ft_newline(backup);
	return (line);
}
