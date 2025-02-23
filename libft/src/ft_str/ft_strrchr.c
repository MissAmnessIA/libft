/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_srchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmesa-ke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:43:35 by vmesa-ke          #+#    #+#             */
/*   Updated: 2024/09/24 14:44:57 by vmesa-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	s += i;
	while (i >= 0)
	{
		if ((unsigned char)*s == (unsigned char)c)
		{
			return (((char *)s));
		}
		i--;
		s--;
	}
	return (NULL);
}
