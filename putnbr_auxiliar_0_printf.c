/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_auxiliar_0_printf.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 10:41:14 by ccardozo          #+#    #+#             */
/*   Updated: 2020/01/09 08:55:11 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	putnbr_auxiliar_0_printf(t_valores **bag, int *diff)
{
	if ((*bag)->precision > 0)
	{
		*diff = (*bag)->precision;
		putzeros(*diff);
		(*bag)->len += *diff;
	}
}
