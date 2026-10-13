/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbustama <dbustama@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 17:39:00 by dbustama          #+#    #+#             */
/*   Updated: 2026/10/13 20:24:01 by dbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_numbers(int n)
{
	char	n_char;
	long	n1;
	int		len;

	len = 0;
	n1 = n;
	if (n1 < 0)
	{
		n1 = -n1;
		write(1, "-", 1);
		len++;
	}
	if (n1 > 9)
		len += print_numbers(n1 / 10);
	n_char = n1 % 10 + '0';
	write(1, &n_char, 1);
	len++;
	return (len);
}

int	print_unsigned_n(unsigned int n)
{
	char	n_char;
	int		len;

	len = 0;
	if (n > 9)
		len = print_numbers(n / 10);
	n_char = n % 10 + '0';
	write(1, &n_char, 1);
	len++;
	return (len);
}