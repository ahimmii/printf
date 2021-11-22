/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahimmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 03:36:22 by ahimmi            #+#    #+#             */
/*   Updated: 2021/11/21 03:36:25 by ahimmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

void	cal(int i, long int nbr, const char *base, int *len);
void	ft_putnbr(int nb, int *len);
void	ft_putnbrhex(unsigned int nb, int tst, int *len);
void	ft_putnbruns(unsigned int nb, int len);
void	printunsigned(unsigned long nb, int *len);
void	printadress(unsigned long nb, int *len);
int		ft_printf(const char *str, ...);

#endif
