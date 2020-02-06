/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_printf_aux.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 14:43:22 by pcuadrad          #+#    #+#             */
/*   Updated: 2020/02/06 13:25:55 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		putnbr_check_zero(t_printf **bag)
{
	int		number;

	number = va_arg((*bag)->argv, int);
	if (number == 0 && (*bag)->precision != -1)
	{
		putnbr_print_0(bag);
		return (0);
	}
	return (number);
}

void	putnbr_width_prec(t_printf **bag, int len, int neg)
{
	int		diff;

	diff = 0;
	if ((*bag)->width > len)
	{
		if ((*bag)->precision > len)
			diff = (*bag)->width - (*bag)->precision - neg;
		else
			diff = (*bag)->width - len - neg;
		putspaces(diff);
		(*bag)->size += diff;
	}
}

void	putnbr_prec_len(t_printf **bag, int len)
{
	int		diff;

	diff = 0;
	if ((*bag)->precision > len)
	{
		diff = (*bag)->precision - len;
		putzeros(diff);
		(*bag)->size += diff;
	}
}

void	putnbr_width_zeros(t_printf **bag, int len, int neg)
{
	int		diff;

	diff = 0;
	if ((*bag)->precision > len)
		diff = (*bag)->width - (*bag)->precision - neg;
	else
		diff = (*bag)->width - len - neg;
	if (diff >= 0)
	{
		if ((*bag)->precision != -1)
			putspaces(diff);
		else
		{
			if (neg)
			{
				ft_putchar('-');
				(*bag)->size += 1;
			}
			putzeros(diff);
		}
		(*bag)->size += diff;
	}
}
