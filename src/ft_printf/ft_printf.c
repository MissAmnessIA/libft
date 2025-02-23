/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmesa-ke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:42:56 by vmesa-ke          #+#    #+#             */
/*   Updated: 2025/02/07 17:47:37 by vmesa-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../inc/libft.h"

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		bytes;

	bytes = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			bytes = type(*str, args, bytes);
		}
		else
			bytes = putchr(*str, bytes);
		str++;
	}
	va_end(args);
	return (bytes);
}
