/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmesa-ke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 23:24:46 by vmesa-ke          #+#    #+#             */
/*   Updated: 2024/09/22 23:00:44 by vmesa-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	total_len;
	size_t	i;
	size_t	e;

	total_len = ft_strlen (src);
	i = ft_strlen(dst);
	e = 0;
	if (size <= i)
		total_len += size;
	else
		total_len += i;
	if (size != 0)
	{
		while (i < size - 1 && src[e] != '\0')
		{
			dst[i] = src[e];
			i++;
			e++;
		}
		dst[i] = '\0';
	}
	return (total_len);
}
