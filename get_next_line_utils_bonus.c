/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatta <amatta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 17:40:31 by amatta            #+#    #+#             */
/*   Updated: 2023/05/17 18:14:52 by amatta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr_nl(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == 10)
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *line, char *buff)
{
	int		i;
	int		j;
	char	*str;

	if (!line)
	{
		line = (char *)malloc(1 * sizeof(char));
		line[0] = '\0';
	}
	if (!line || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(line) + ft_strlen(buff)) + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (line[++i])
		str[i] = line[i];
	j = 0;
	while (buff[j])
		str[i++] = buff[j++];
	str[i] = '\0';
	free(line);
	return (str);
}

char	*ft_newline(char *backup)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (backup[i] && backup[i] != 10)
		i++;
	if (!backup[i])
	{
		free(backup);
		return (NULL);
	}
	str = (char *)malloc(sizeof (char) * (ft_strlen(backup) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (backup[i])
		str[j++] = backup[i++];
	str[j] = 0;
	free(backup);
	return (str);
}
