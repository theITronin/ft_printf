/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbustama <dbustama@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 13:14:37 by dbustama          #+#    #+#             */
/*   Updated: 2026/10/12 13:49:31 by dbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *format, ...)
{
	va_list	args;
	size_t	i;

	va_start(args, format);
	while(!format[i])
	{
		if (format[i] == '%')
		{
			i++;
			foud_type(format[i]);
		}
		i++;
	}
	va_end(args);
}

void	foud_type(char	c)
{
	if (c == 'c')
		write(1, &c, 1);
	if (c == 's')
		ft_putstr_fd(c, 1);
	if (c == 'p')
		
}
