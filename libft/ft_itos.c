/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 16:24:57 by eleclet           #+#    #+#             */
/*   Updated: 2019/05/01 17:29:58 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itos(long long int	nbr, int base, int xupper)
{
	char neg;
	char *r;
	int i;

	r = malloc(100);
	ft_bzero(r, 100);
	if (nbr == 0)
		ft_putchar('0');
	if (nbr < 0)
	{
		neg = 1;
		nbr = nbr * -1;
	}
	else
		neg = 0;

	i = 0;
	while (nbr > 0)
	{
		if (nbr % base > 10)
			if (xupper)
				r[i] = nbr % base + 65 - 10;
			else
				r[i] = nbr % base + 97 - 10;
		else
		{
			r[i] = nbr % base + 48;
		}
		nbr /= base;
		i++;
	}
	if (neg)
		r[i] = '-';
	r = ft_strrvrs(r);
	//ft_putstr(r);
	return (r);
}
