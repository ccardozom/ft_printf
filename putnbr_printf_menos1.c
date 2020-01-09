/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_printf_menos1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 11:25:41 by ccardozo          #+#    #+#             */
/*   Updated: 2020/01/09 08:55:48 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	putnbr_printf_menos1(t_valores **bag)
{
	int number;
	int len;
	int neg;

	if ((number = putnbr_check_zero(bag)) == 0 && (*bag)->precision != -1)
		return ;
	len = ft_nbrlenprec(number);
	neg = 0;
	if (number < 0)
	{
		ft_putchar('-');
		neg = 1;
		(*bag)->len = (*bag)->len + 1;
	}
	putnbr_prec_len(bag, len);
	ft_putnbrprintfprec(number, bag);
	putnbr_width_prec(bag, len, neg);
}