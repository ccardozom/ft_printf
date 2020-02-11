/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 13:49:40 by pcuadrad          #+#    #+#             */
/*   Updated: 2020/02/06 13:25:05 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		processline(t_printf **bag)
{
	int			j;

	j = -1;
	while ((*bag)->format[++j])
	{
		if ((*bag)->format[j] == '%')
		{
			reinitialize(bag);
			j += destructor((*bag)->format + j + 1, bag);
		}
		else
			(*bag)->size += write(1, &(*bag)->format[j], 1);
	}
}
