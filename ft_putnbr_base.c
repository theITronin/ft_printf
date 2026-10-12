/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbustama <dbustama@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 17:29:13 by dbustama          #+#    #+#             */
/*   Updated: 2026/10/12 17:42:55 by dbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_patch_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (!base || !base[0] || !base[1])
		return (1);
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-' || base[i] <= 32 || base[i] == 127)
			return (1);
		j = 0;
		while (base[j] != '\0')
		{
			if (base[i] == base[j] && i != j)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

size_t	ft_putnbr_base(int nbr, char *base)
{
	long	n;
	int		counter;
	size_t	len;

	len = 0;
	counter = 0;
	if (ft_patch_base(base) == 1)
		return (0);
	while (base[counter] != '\0')
		counter++;
	n = nbr;
	if (n < 0)
	{
		n = -n;
		write(1, "-", 1);
		len++;
	}
	if (n >= counter)
		len = ft_putnbr_base(n / counter, base);
	write(1, &base[n % counter], 1);
	len++;
	return (len);
}
