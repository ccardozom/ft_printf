/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_printf_precision.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 07:48:22 by ccardozo          #+#    #+#             */
/*   Updated: 2020/01/09 08:55:52 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void    putnbr_printf_precision(t_valores **bag)
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
		(*bag)->len += 1;
	}
	putnbr_prec_len(bag, len);
	ft_putnbrprintfprec(number, bag);
}