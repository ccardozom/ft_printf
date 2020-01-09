/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putunsigned_printf.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 08:12:05 by ccardozo          #+#    #+#             */
/*   Updated: 2020/01/09 09:51:26 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void		putunsigned_printf_1minus(t_valores **bag)
{
	unsigned int		number;
	int					len;

	if ((number = putunsigned_check_zero(bag)) == 0 && (*bag)->precision != -1)
		return ;
	len = ft_nbrulen(number);
	putnbr_prec_len(bag, len);
	ft_putnbru(number, bag);
	putnbr_width_prec(bag, len, 0);
}

static void		putunsigned_printf_0minus(t_valores **bag)
{
	int				len;
	unsigned int	number;
	int				diff;

	if ((number = putunsigned_check_zero(bag)) == 0 && (*bag)->precision != -1)
		return ;
	len = ft_nbrulen(number);
	if ((*bag)->width > len)
	{
		diff = (*bag)->width - len;
		putspaces(diff);
		(*bag)->len += diff;
	}
	ft_putnbru(number, bag);
}

static void		putunsigned_printf_zeros(t_valores **bag)
{
	unsigned int		number;
	int					len;

	if ((number = putunsigned_check_zero(bag)) == 0 && (*bag)->precision != -1)
		return ;
	len = ft_nbrulen(number);
	if ((*bag)->width > len)
		putnbr_width_zeros(bag, len, 0);
	putnbr_prec_len(bag, len);
	ft_putnbru(number, bag);
}

static void		putunsigned_printf_precision(t_valores **bag)
{
	int				len;
	unsigned int	number;

	if ((number = putunsigned_check_zero(bag)) == 0 && (*bag)->precision != -1)
		return ;
	len = ft_nbrulen(number);
	putnbr_width_prec(bag, len, 0);
	putnbr_prec_len(bag, len);
	ft_putnbru(number, bag);
}

void			putunsigned_printf(t_valores **bag)
{
	if ((*bag)->menos == 1)
		putunsigned_printf_1minus(bag);
	else if ((*bag)->menos == 0)
	{
		if ((*bag)->zero == 1)
			putunsigned_printf_zeros(bag);
		else if ((*bag)->precision > -1)
			putunsigned_printf_precision(bag);
		else
			putunsigned_printf_0minus(bag);
	}
}
