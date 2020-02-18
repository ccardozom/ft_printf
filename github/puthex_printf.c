/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puthex_printf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 17:49:47 by pcuadrad          #+#    #+#             */
/*   Updated: 2020/02/06 13:25:33 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void		puthex_printf_1minus(t_printf **bag)
{
	unsigned int		number;
	int					len;

	if ((number = putnbr_check_zero(bag)) == 0 && (*bag)->precision != -1)
		return ;
	len = ft_nbrhexlen(number);
	putnbr_prec_len(bag, len);
	printf_hex(number, bag);
	putnbr_width_prec(bag, len, 0);
}

static void		puthex_printf_0minus(t_printf **bag)
{
	int				len;
	unsigned int	number;
	int				diff;

	if ((number = putnbr_check_zero(bag)) == 0 && (*bag)->precision != -1)
		return ;
	len = ft_nbrhexlen(number);
	if ((*bag)->width > len)
	{
		diff = (*bag)->width - len;
		putspaces(diff);
		(*bag)->size += diff;
	}
	printf_hex(number, bag);
}

static void		puthex_printf_zeros(t_printf **bag)
{
	unsigned int		number;
	int					len;

	if ((number = putnbr_check_zero(bag)) == 0 && (*bag)->precision != -1)
		return ;
	len = ft_nbrhexlen(number);
	if ((*bag)->width > len)
		putnbr_width_zeros(bag, len, 0);
	putnbr_prec_len(bag, len);
	printf_hex(number, bag);
}

static void		puthex_printf_precision(t_printf **bag)
{
	int				len;
	unsigned int	number;

	if ((number = putnbr_check_zero(bag)) == 0 && (*bag)->precision != -1)
		return ;
	len = ft_nbrhexlen(number);
	putnbr_width_prec(bag, len, 0);
	putnbr_prec_len(bag, len);
	printf_hex(number, bag);
}

void			puthex_printf(t_printf **bag)
{
	if ((*bag)->minus == 1)
		puthex_printf_1minus(bag);
	else if ((*bag)->minus == 0)
	{
		if ((*bag)->zero == 1)
			puthex_printf_zeros(bag);
		else if ((*bag)->precision > -1)
			puthex_printf_precision(bag);
		else
			puthex_printf_0minus(bag);
	}
}
