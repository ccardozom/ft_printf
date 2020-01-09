/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putmemory_printf_.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 14:08:05 by ccardozo          #+#    #+#             */
/*   Updated: 2020/01/08 14:51:07 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void		putmemory_printf_1minus(t_valores **bag)
{
	t_uintptr		number;
	int				len;

	if ((number = (t_uintptr)va_arg((*bag)->ap, void*)) == 0)
	{
		putmemory_nill(bag);
		return ;
	}
	len = ft_nbrmemlen(number);
	len += ((*bag)->precision > len) ? 0 : 2;
	printf_0x(bag);
	putnbr_prec_len(bag, len);
	ft_putnbr_base_mem(number, HEX, bag);
	(*bag)->precision += ((*bag)->precision > len) ? 2 : 0;
	putnbr_width_prec(bag, len, 0);
}

static void		putmemory_printf_0minus(t_valores **bag)
{
	int				len;
	t_uintptr		number;
	int				diff;

	if ((number = (t_uintptr)va_arg((*bag)->ap, void*)) == 0)
	{
		putmemory_nill(bag);
		return ;
	}
	len = ft_nbrmemlen(number) + 2;
	if ((*bag)->width > len)
	{
		diff = (*bag)->width - len;
		putspaces(diff);
		(*bag)->len += diff;
	}
	printf_0x(bag);
	ft_putnbr_base_mem(number, HEX, bag);
}

static void		putmemory_printf_zeros(t_valores **bag)
{
	t_uintptr		number;
	int				len;

	if ((number = (t_uintptr)va_arg((*bag)->ap, void*)) == 0)
	{
		putmemory_nill(bag);
		return ;
	}
	len = ft_nbrmemlen(number);
	printf_0x(bag);
	len += ((*bag)->precision > len) ? 0 : 2;
	if ((*bag)->width > len)
		putnbr_width_zeros(bag, len, 0);
	putnbr_prec_len(bag, len);
	ft_putnbr_base_mem(number, HEX, bag);
}

static void		putmemory_printf_precision(t_valores **bag)
{
	int				len;
	t_uintptr		number;

	if ((number = (t_uintptr)va_arg((*bag)->ap, void*)) == 0)
	{
		putmemory_nill(bag);
		return ;
	}
	len = ft_nbrmemlen(number) + 2;
	putnbr_width_prec(bag, len, 0);
	printf_0x(bag);
	putnbr_prec_len(bag, len - 2);
	ft_putnbr_base_mem(number, HEX, bag);
}

void			putmemory_printf(t_valores **bag)
{
	if ((*bag)->menos == 1)
		putmemory_printf_1minus(bag);
	else if ((*bag)->menos == 0)
	{
		if ((*bag)->zero == 1)
			putmemory_printf_zeros(bag);
		else if ((*bag)->precision > -1)
			putmemory_printf_precision(bag);
		else
			putmemory_printf_0minus(bag);
	}
}
