/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmesa-ke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 22:05:35 by vmesa-ke          #+#    #+#             */
/*   Updated: 2024/10/07 22:06:06 by vmesa-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	check_set(const char *set, char c)
{
	while (*set)
	{
		if (*set == c)
		{
			return (1);
		}
		set++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	const char	*start;
	const char	*fin;
	char		*trim;
	size_t		size_s1;
	int			count;

	count = 0;
	size_s1 = ft_strlen (s1);
	start = s1;
	fin = (s1 + size_s1) - 1;
	while (check_set(set, *start) && *start)
		start++;
	while (check_set(set, *fin) && fin > start)
		fin--;
	trim = (char *)malloc((fin - start) + 2);
	if (!trim)
		return (NULL);
	while (start <= fin)
	{
		trim[count] = *start;
		count++;
		start++;
	}
	trim[count] = '\0';
	return (trim);
}
