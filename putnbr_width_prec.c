/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_width_prec.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 09:02:59 by ccardozo          #+#    #+#             */
/*   Updated: 2020/01/09 09:03:33 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	putnbr_width_prec(t_valores **bag, int len, int neg)
{
	int diff;

	diff = 0;
	if ((*bag)->width > len)
	{
		if ((*bag)->precision > len)
			diff = (*bag)->width - (*bag)->precision - neg;
		else
			diff = (*bag)->width - len - neg;
		putspaces(diff);
	}
}