/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmesa-ke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:05:45 by vmesa-ke          #+#    #+#             */
/*   Updated: 2024/11/15 16:05:50 by vmesa-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../inc/libft.h"

char	*strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if ((unsigned char)*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

char	*lost_chars(char	*saved)
{
	char	*new_save;
	int		i;
	char	*ptr;

	i = 0;
	ptr = saved;
	while (*ptr != '\n')
		ptr++;
	ptr++;
	while (ptr[i])
		i++;
	new_save = (char *)malloc(i + 1);
	if (!new_save)
		return (NULL);
	i = 0;
	while (*ptr)
	{
		new_save[i] = *ptr;
		i++;
		ptr++;
	}
	free(saved);
	new_save[i] = '\0';
	return (new_save);
}

char	*strjoin(char *save, char *readed)
{
	char	*joined;
	int		i;
	char	*cpysaved;

	cpysaved = save;
	i = 0;
	joined = (char *)malloc(ft_strlen(cpysaved) + ft_strlen(readed) + 1);
	while (*cpysaved)
	{
		joined[i] = *cpysaved;
		i++;
		cpysaved++;
	}
	while (*readed)
	{
		joined[i] = *readed;
		i++;
		readed++;
	}
	joined[i] = '\0';
	free(save);
	return (joined);
}

char	*cut_line(char	*saved)
{
	char	*line;
	int		i;

	i = 0;
	if (saved[i] == '\0')
		return (NULL);
	while (saved[i] != '\n' && saved[i])
		i++;
	line = (char *)malloc(i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (saved[i] && saved[i] != '\n')
	{
		line[i] = saved[i];
		i++;
	}
	if (saved[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
