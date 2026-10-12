/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbustama <dbustama@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 10:24:38 by dbustama          #+#    #+#             */
/*   Updated: 2026/10/12 17:38:56 by dbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stddef.h>

int		ft_printf(char const *format, ...);
int		ft_patch_base(char *base);

size_t	foud_type(char c, va_list args);
size_t	print_string(char *str);
size_t	print_numbers(int n, char c);
size_t	print_hexadecimal(int n, char c);
size_t	ft_putnbr_base(int nbr, char *base);

#endif