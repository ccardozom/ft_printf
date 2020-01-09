/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_printf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 08:59:59 by ccardozo          #+#    #+#             */
/*   Updated: 2020/01/09 09:00:00 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void    putnbr_printf(t_valores **bag)
{
    if ((*bag)->menos == 1)
        putnbr_printf_menos1(bag);
    else if ((*bag)->menos == 0)
    {
        if ((*bag)->zero == 1)
            putnbr_printf_zeros(bag);
        else if ((*bag)->precision > -1)
            putnbr_printf_precision(bag);
        else
            putnbr_printf_menos0(bag);        
    }
}