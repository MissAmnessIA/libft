/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmesa-ke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:26:34 by vmesa-ke          #+#    #+#             */
/*   Updated: 2024/10/23 19:26:36 by vmesa-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	type(char c, va_list args, int bytes)
{
	if (c == 'c')
		bytes = putchr(va_arg(args, int), bytes);
	else if (c == 's')
		bytes = putstr(va_arg(args, char *), bytes);
	else if (c == 'p')
		bytes = ptrcheck(va_arg(args, unsigned long long), bytes);
	else if (c == 'd' || c == 'i')
		bytes = ft_putnbr(va_arg(args, int), bytes);
	else if (c == 'u')
		bytes = unsignedint(va_arg(args, unsigned int), bytes);
	else if (c == 'x' || c == 'X')
		bytes = print_hex(va_arg(args, unsigned int), bytes, c);
	else if (c == '%')
		bytes += write(1, "%", 1);
	return (bytes);
}

int	ptrcheck(unsigned long long ptr, int bytes)
{
	if (!ptr)
	{
		bytes = putstr("(nil)", bytes);
		return (bytes);
	}
	bytes = putstr("0x", bytes);
	bytes = put_ptr_hex(ptr, bytes);
	return (bytes);
}

int	unsignedint(unsigned int n, int bytes)
{
	if (n >= 10)
		bytes = unsignedint(n / 10, bytes);
	bytes = putchr(n % 10 + '0', bytes);
	return (bytes);
}

int	put_ptr_hex(unsigned long long ptr, int bytes)
{
	if (ptr == 0)
		bytes = putchr ('0', bytes);
	if (ptr >= 16)
		bytes = put_ptr_hex(ptr / 16, bytes);
	if (ptr % 16 <= 9)
		bytes = putchr(ptr % 16 + '0', bytes);
	if (ptr % 16 > 9)
		bytes = putchr((ptr % 16) % 10 + 'a', bytes);
	return (bytes);
}

int	print_hex(unsigned int n, int bytes, char c)
{
	if (n == 0)
		bytes = putchr ('0', bytes);
	if (n >= 16)
		bytes = print_hex(n / 16, bytes, c);
	if (n % 16 <= 9)
		bytes = putchr(n % 16 + '0', bytes);
	if (n % 16 > 9)
	{
		if (c == 'X')
			bytes = putchr((n % 16) % 10 + 'A', bytes);
		else
			bytes = putchr((n % 16) % 10 + 'a', bytes);
	}
	return (bytes);
}
