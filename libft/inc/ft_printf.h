/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmesa-ke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:29:34 by vmesa-ke          #+#    #+#             */
/*   Updated: 2024/10/23 19:29:36 by vmesa-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdarg.h>

int	ptrcheck(unsigned long long ptr, int bytes);
int	type(char c, va_list args, int bytes);
int	putstr(char *str, int bytes);
int	putchr(int c, int bytes);
int	put_ptr_hex(unsigned long long ptr, int bytes);
int	ft_putnbr(int n, int bytes);
int	unsignedint(unsigned int n, int bytes);
int	print_hex(unsigned int n, int bytes, char c);
int	ft_printf(char const *str, ...);
