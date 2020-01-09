/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_precision_len.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 10:46:03 by ccardozo          #+#    #+#             */
/*   Updated: 2020/01/09 08:55:22 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	putnbr_prec_len(t_valores **bag, int len)
{
	int diff;

	diff = 0;
	if ((*bag)->precision > len)
	{
		diff = (*bag)->precision - len;
		putzeros(diff);
		(*bag)->len += diff;
	}
}
