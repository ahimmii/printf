/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahimmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 19:34:03 by ahimmi            #+#    #+#             */
/*   Updated: 2021/11/20 19:34:05 by ahimmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	cal(int i, int nbr, const char *base, int *len)
{
	if (nbr == -2147483648)
	{
		*len += write(1, "-2147483648", 11);
		return ;
	}
	if (nbr < 0)
	{
		nbr *= -1;
		*len += write(1, "-", 1);
	}
	if (nbr >= i)
	{
		cal(i, nbr / i, base, len);
		cal(i, nbr % i, base, len);
	}
	else
		*len += write(1, base + nbr, 1);
}

void	printadress(unsigned long nb, int *len)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (nb >= 16)
	{
		printadress(nb / 16, len);
		printadress(nb % 16, len);
	}
	else
		*len += write(1, &hex[nb], 1);
}

void	printhex(unsigned int nb, int tst, int *len)
{
	if (nb >= 16)
	{
		printhex(nb / 16, tst, len);
		printhex(nb % 16, tst, len);
	}
	else
	{
		if (tst == 0)
			*len += write(1, &"0123456789ABCDEF"[nb], 1);
		else if (tst == 1)
			*len += write(1, &"0123456789abcdef"[nb], 1);
	}
}

void	printunsigned(unsigned int nb, int *len)
{
	char	*n;

	n = "0123456789";
	if (nb >= 10)
	{
		printunsigned(nb / 10, len);
		printunsigned(nb % 10, len);
	}
	else
		*len += write(1, &n[nb], 1);
}
