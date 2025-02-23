/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmesa-ke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 21:57:57 by vmesa-ke          #+#    #+#             */
/*   Updated: 2024/10/07 23:08:09 by vmesa-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	char	*d_s;
	size_t	i;

	i = 0;
	d_s = (char *)s;
	dup = (char *) malloc(ft_strlen(d_s) + 1);
	if (!dup)
		return (NULL);
	while (d_s[i] != '\0')
	{
		dup[i] = d_s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
