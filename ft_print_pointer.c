/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbustama <dbustama@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 18:38:04 by dbustama          #+#    #+#             */
/*   Updated: 2026/10/14 15:51:33 by dbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putlong_base(unsigned long nbr, char *base)
{
	unsigned long		counter;
	int					len;

	len = 0;
	counter = 0;
	while (base[counter] != '\0')
		counter++;
	if (nbr >= counter)
		len += ft_putlong_base(nbr / counter, base);
	write(1, &base[nbr % counter], 1);
	len++;
	return (len);
}

int	print_long_hexadecimal(unsigned long n, char c)
{
	if (c == 'x')
		return (ft_putlong_base(n, "0123456789abcdef"));
	if (c == 'X')
		return (ft_putlong_base(n, "0123456789ABCDEF"));
	return (0);
}

int	print_pointer(unsigned long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (print_string("(nil)"));
	len = print_string("0x");
	len += print_long_hexadecimal(n, 'x');
	return (len);
}
