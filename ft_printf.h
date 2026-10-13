/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbustama <dbustama@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 10:24:38 by dbustama          #+#    #+#             */
/*   Updated: 2026/10/13 20:17:24 by dbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stddef.h>

int		ft_printf(char const *format, ...);

size_t	foud_type(char c, va_list args);
size_t	print_string(char *str);
size_t	print_numbers(int n);
size_t	print_nbr_hexadecimal(unsigned int n, char c);
size_t	ft_putnbr_base(unsigned int nbr, char *base);
size_t	print_long_hexadecimal(unsigned long n, char c);
size_t	ft_putlong_base(unsigned long nbr, char *base);
size_t	print_unsigned_n(unsigned int n);
size_t	print_pointer(unsigned long n);

#endif