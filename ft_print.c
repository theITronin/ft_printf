/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbustama <dbustama@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 13:14:37 by dbustama          #+#    #+#             */
/*   Updated: 2026/10/14 15:50:53 by dbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		i;
	int		print_bytes;

	print_bytes = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			print_bytes += foud_type(format[i], args);
		}
		else if (format[i] != '%')
		{
			write(1, &format[i], 1);
			print_bytes++;
		}
		i++;
	}
	va_end(args);
	return (print_bytes);
}

int	foud_type(char c, va_list args)
{
	if (c == 'c')
		return (print_char(va_arg(args, int)));
	else if (c == 's')
		return (print_string(va_arg(args, char *)));
	else if (c == 'p')
		return (print_pointer(va_arg(args, unsigned long)));
	else if (c == 'd' || c == 'i')
		return (print_numbers(va_arg(args, int)));
	else if (c == 'u')
		return (print_unsigned_n(va_arg(args, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (print_nbr_hexadecimal(va_arg(args, unsigned int), c));
	else if (c == '%')
		return (print_char('%'));
	return (0);
}
