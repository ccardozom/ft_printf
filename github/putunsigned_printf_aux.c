/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putunsigned_printf_aux.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 16:22:40 by pcuadrad          #+#    #+#             */
/*   Updated: 2020/02/06 13:26:42 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

unsigned int		putunsigned_check_zero(t_printf **bag)
{
	unsigned int	number;

	number = (unsigned int)va_arg((*bag)->argv, int);
	if (number == 0 && (*bag)->precision != -1)
	{
		putnbr_print_0(bag);
		return (0);
	}
	return (number);
}

void				ft_putnbru(unsigned int nb, t_printf **bag)
{
	if (nb >= 10)
		ft_putnbru(nb / 10, bag);
	ft_putchar(nb % 10 + '0');
	(*bag)->size += 1;
}
