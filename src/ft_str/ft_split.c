/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmesa-ke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 22:09:00 by vmesa-ke          #+#    #+#             */
/*   Updated: 2024/10/10 17:08:53 by vmesa-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	count_substr(const char *s, char c)
{
	int	count;
	int	in_str;

	count = 0;
	in_str = 0;
	while (*s)
	{
		if (*s != c && !in_str)
		{
			in_str = 1;
			count++;
		}
		else if (*s == c)
			in_str = 0;
		s++;
	}
	return (count);
}

size_t	size_substr(const char *s, char c, unsigned int index)
{
	size_t	count;

	count = 0;
	while (s[index] && s[index] != c)
	{
		count++;
		index++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char			**result;
	unsigned int	index;
	size_t			substr_size;
	int				i;

	result = (char **)malloc((count_substr(s, c) + 1) * sizeof(char *));
	if (!result || !s)
		return (NULL);
	index = 0;
	i = 0;
	while (s[index])
	{
		while (s[index] == c && s[index])
			index++;
		if (s[index] != c && s[index])
		{
			substr_size = size_substr (s, c, index);
			result[i] = ft_substr (s, index, substr_size);
			index += substr_size;
			i++;
		}
	}
	result[i] = NULL;
	return (result);
}
