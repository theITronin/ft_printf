/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbustama <dbustama@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 13:14:37 by dbustama          #+#    #+#             */
/*   Updated: 2026/10/12 18:04:51 by dbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *format, ...)
{
	va_list	args;
	size_t	i;
	size_t	print_bytes;

	print_bytes = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			print_bytes = print_bytes + foud_type(format[i], args);
			i++;
		}
		else
		{	
			write(1, &format[i], 1);
			print_bytes++;
			i++;
		}
	}
	va_end(args);
	return (print_bytes);
}

size_t	foud_type(char c, va_list args)
{
	if (c == 'c')
	{
		ft_putchar_fd(va_arg(args, int), 1);
		return (1);
	}
	else if (c == 's')
		return (print_string(va_arg(args, char *)));
	else if (c == 'p')
	{}
	else if (c == 'd' || c == 'i' || c == 'u')
		return (print_numbers(va_arg(args, int), c));
	else if (c == 'x' || c == 'X')
		return (print_hexadecimal(va_arg(args, unsigned int), c));
	else if (c == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	return (0);
}

size_t	print_string(char *str)
{
	if (!str)
	{
		ft_putstr_fd("(null)" ,1);
		return (0);
	}
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

size_t	print_numbers(int n, char c)
{
	char	n_char;
	long	n1;
	size_t	len;

	len = 0;
	n1 = n;
	if (n1 < 0 && c != 'u')
	{
		write(1, "-", 1);
		len++;
	}
	if (n1 < 0)
		n1 = -n1;
	if (n1 > 9)
		len = print_numbers(n1 / 10, c);
	n_char = n1 % 10 + '0';
	write(1, &n_char, 1);
	len++;
	return (len);
}

size_t	print_hexadecimal(int n, char c)
{
	if (c == 'x')
		return (ft_putnbr_base(n, "0123456789abcdef"));
	if (c == 'X')
		return (ft_putnbr_base(n, "0123456789ABCDEF"));
	return (0);
}
