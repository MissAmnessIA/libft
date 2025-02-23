/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmesa-ke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:59:05 by vmesa-ke          #+#    #+#             */
/*   Updated: 2024/10/07 22:32:14 by vmesa-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isspace(const char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *nptr)
{
	long long	i;
	int			neg;

	i = 0;
	neg = 1;
	while (ft_isspace ((unsigned char)*nptr))
		nptr++;
	if ((unsigned char)*nptr == '-' || (unsigned char)*nptr == '+')
	{
		if ((unsigned char)*nptr == '-')
			neg *= -1;
		nptr++;
	}
	if (!ft_isdigit((unsigned char)*nptr))
		return (0);
	while (ft_isdigit((unsigned char)*nptr))
	{
		i += ((unsigned char)*nptr - 48);
		i *= 10;
		nptr++;
	}
	return (i / 10 * neg);
}
