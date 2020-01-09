/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_check_zero.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 10:44:51 by ccardozo          #+#    #+#             */
/*   Updated: 2020/01/09 08:55:18 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		putnbr_check_zero(t_valores **bag)
{
	int num;

	num = va_arg((*bag)->ap, int);
	if (num == 0 && (*bag)->precision != -1)
	{
		putnbr_printf_0(bag);
		return (0);
	}
	return (num);
}
