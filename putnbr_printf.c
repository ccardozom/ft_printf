/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_printf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 14:31:12 by pcuadrad          #+#    #+#             */
/*   Updated: 2020/02/06 13:26:12 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void		putnbr_printf_1minus(t_printf **bag)
{
	int		number;
	int		len;
	int		neg;

	if ((number = putnbr_check_zero(bag)) == 0 && (*bag)->precision != -1)
		return ;
	len = ft_nbrlenprec(number);
	neg = 0;
	if (number < 0)
	{
		ft_putchar('-');
		neg = 1;
		(*bag)->size += 1;
	}
	putnbr_prec_len(bag, len);
	ft_putnbrprintfprec(number, bag);
	putnbr_width_prec(bag, len, neg);
}

static void		putnbr_printf_0minus(t_printf **bag)
{
	int		diff;
	int		number;

	if ((number = putnbr_check_zero(bag)) == 0 && (*bag)->precision != -1)
		return ;
	diff = ft_nbrlen(number);
	if ((*bag)->width > diff)
	{
		diff = (*bag)->width - diff;
		putspaces(diff);
		(*bag)->size += diff;
	}
	ft_putnbrprintf(number, bag);
}

static void		putnbr_printf_zeros(t_printf **bag)
{
	int		number;
	int		neg;
	int		len;

	if ((number = putnbr_check_zero(bag)) == 0 && (*bag)->precision != -1)
		return ;
	len = ft_nbrlenprec(number);
	neg = (number < 0) ? 1 : 0;
	if ((*bag)->width > len)
		putnbr_width_zeros(bag, len, neg);
	if (neg && ((*bag)->precision != -1 || len >= (*bag)->width))
	{
		ft_putchar('-');
		(*bag)->size += 1;
	}
	putnbr_prec_len(bag, len);
	ft_putnbrprintfprec(number, bag);
}

static void		putnbr_printf_precision(t_printf **bag)
{
	int		len;
	int		number;
	int		neg;

	if ((number = putnbr_check_zero(bag)) == 0 && (*bag)->precision != -1)
		return ;
	len = ft_nbrlenprec(number);
	neg = (number < 0) ? 1 : 0;
	putnbr_width_prec(bag, len, neg);
	if (neg)
	{
		ft_putchar('-');
		(*bag)->size += 1;
	}
	putnbr_prec_len(bag, len);
	ft_putnbrprintfprec(number, bag);
}

void			putnbr_printf(t_printf **bag)
{
	if ((*bag)->minus == 1)
		putnbr_printf_1minus(bag);
	else if ((*bag)->minus == 0)
	{
		if ((*bag)->zero == 1)
			putnbr_printf_zeros(bag);
		else if ((*bag)->precision > -1)
			putnbr_printf_precision(bag);
		else
			putnbr_printf_0minus(bag);
	}
}
