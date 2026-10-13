/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbustama <dbustama@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 10:24:38 by dbustama          #+#    #+#             */
/*   Updated: 2026/10/13 20:50:35 by dbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stddef.h>

int	ft_printf(char const *format, ...);
int	foud_type(char c, va_list args);
int	print_string(char *str);
int	print_numbers(int n);
int	print_nbr_hexadecimal(unsigned int n, char c);
int	ft_putnbr_base(unsigned int nbr, char *base);
int	print_long_hexadecimal(unsigned long n, char c);
int	ft_putlong_base(unsigned long nbr, char *base);
int	print_unsigned_n(unsigned int n);
int	print_pointer(unsigned long n);
int	print_char(char c);

#endif