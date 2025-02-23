/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmesa-ke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:23:38 by vmesa-ke          #+#    #+#             */
/*   Updated: 2024/10/07 22:50:03 by vmesa-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	e;

	i = 0;
	if (*little == '\0' || little == NULL )
		return ((char *)big);
	else if (*big == '\0' || len == 0)
		return (NULL);
	while (i < len && big[i] != '\0')
	{
		e = 0;
		while (big[i + e] == little[e] && i + e < len)
		{
			if (little[e + 1] == '\0')
				return ((char *)big + i);
			e++;
		}
		i++;
	}
	return (NULL);
}
