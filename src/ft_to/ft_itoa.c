/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmesa-ke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 22:08:01 by vmesa-ke          #+#    #+#             */
/*   Updated: 2024/10/10 17:52:10 by vmesa-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	numsize(long int cpyn)
{
	int	count;

	count = 0;
	if (cpyn == 0)
		return (1);
	if (cpyn < 0)
	{
		count++;
		cpyn *= -1;
	}
	while (cpyn != 0)
	{
		cpyn /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	long int	cpyn;
	char		*strn;
	int			sizen;

	cpyn = n;
	sizen = numsize(cpyn);
	strn = (char *)malloc(sizen + 1);
	if (!strn)
		return (NULL);
	if (cpyn < 0)
		cpyn *= -1;
	strn[sizen] = '\0';
	sizen--;
	while (cpyn != 0)
	{
		strn[sizen] = (cpyn % 10) + '0';
		cpyn /= 10;
		sizen--;
	}
	if (n < 0)
		strn[0] = '-';
	else if (n == 0)
		strn[0] = '0';
	return (strn);
}
