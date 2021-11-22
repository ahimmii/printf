/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahimmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 19:33:51 by ahimmi            #+#    #+#             */
/*   Updated: 2021/11/20 19:33:55 by ahimmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printf_str(const char *s, va_list list, int *len)
{
	char	*str;
	char	c;
	int		i;

	i = 0;
	if (*s == 's')
	{
		str = va_arg(list, char *);
		if (!str)
		{
			*len += write(1, "(null)", 6);
			return ;
		}
		while (str[i])
		*len += write(1, &str[i++], 1);
	}
	else if (*s == 'c')
	{
		c = va_arg(list, int);
		*len += write(1, &c, 1);
	}
}

void	printf_di(const char *s, va_list list, int *len)
{
	int				d;
	unsigned int	u;

	if (*s == 'd' || *s == 'i')
	{
		d = va_arg(list, int);
		cal(10, d, "0123456789", len);
	}
	if (*s == 'u')
	{
		u = va_arg(list, unsigned int);
		printunsigned(u, len);
	}
}

void	printf_hex(const char *s, va_list list, int *len)
{
	unsigned int	n;
	unsigned long	p;
	int				tst;

	tst = 0;
	if (*s == 'x' || *s == 'X' )
	{
		n = va_arg(list, unsigned int);
		if (*s == 'x')
			tst = 1;
		ft_putnbrhex(n, tst, len);
	}
	else if (*s == 'p')
	{
		p = va_arg(list, unsigned long);
		*len += write(1, "0x", 2);
		printadress(p, len);
	}
}

int	ft_printf(const char *str, ...)
{
	va_list		list;
	int			len;
	int			i;

	va_start (list, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[++i] != '%')
			{
				printf_str(&str[i], list, &len);
				printf_di(&str[i], list, &len);
				printf_hex(&str[i], list, &len);
			}
			else
			len += write(1, &str[i], 1);
		}
		else
			len += write(1, &str[i], 1);
		i++;
	}
	return (va_end(list), len);
}
