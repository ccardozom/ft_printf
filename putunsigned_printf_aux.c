/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putunsigned_printf_aux.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 08:14:19 by ccardozo          #+#    #+#             */
/*   Updated: 2020/01/09 08:56:28 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

unsigned int		putunsigned_check_zero(t_valores **bag)
{
	unsigned int	number;

	number = (unsigned int)va_arg((*bag)->ap, int);
	if (number == 0 && (*bag)->precision != -1)
	{
		putnbr_printf_0(bag);
		return (0);
	}
	return (number);
}

void				ft_putnbru(unsigned int nb, t_valores **bag)
{
	if (nb >= 10)
		ft_putnbru(nb / 10, bag);
	ft_putchar(nb % 10 + '0');
	(*bag)->len += 1;
}