/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_printf_zeros.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 07:36:44 by ccardozo          #+#    #+#             */
/*   Updated: 2020/01/09 08:55:55 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void    putnbr_printf_zeros(t_valores **bag)
{
    int number;
    int neg;
    int len;

    if ((number = putnbr_check_zero(bag)) == 0 && (*bag)->precision != -1)
        return;
    len = ft_nbrlenprec(number);
    neg = (number < 0) ? 1 : 0;
    if ((*bag)->width > len)
        putnbr_width_zeros(bag, len, neg);
    if (neg && ((*bag)->precision != -1 || len >= (*bag)->width))
    {
        ft_putchar('-');
        (*bag)->len += 1;
    }
    putnbr_prec_len(bag, len);
    ft_putnbrprintfprec(number, bag);
}