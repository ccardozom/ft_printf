/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_printf_0.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 08:22:23 by ccardozo          #+#    #+#             */
/*   Updated: 2020/01/09 08:55:32 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	putnbr_printf_0(t_valores **bag)
{
	int diff;

	diff = 0;
	if ((*bag)->menos == 1)
	{
		putnbr_auxiliar_0_printf(bag, &diff);
		putnbr_width_prec(bag, diff, 0);
	}
	else
	{
		putnbr_width_prec(bag, diff, 0);
		putnbr_auxiliar_0_printf(bag, &diff);
	}
}
