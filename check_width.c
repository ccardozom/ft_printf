/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 13:20:56 by ccardozo          #+#    #+#             */
/*   Updated: 2020/02/06 13:20:58 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	check_width(t_printf **bag)
{
	int		i;
	int		cont;

	i = 0;
	cont = 0;
	while ((*bag)->summary[i] && (*bag)->summary[i] != '.')
	{
		if ((*bag)->summary[i] == '*')
		{
			if (((*bag)->width = (int)va_arg((*bag)->argv, int)) < 0)
			{
				(*bag)->minus = 1;
				(*bag)->width *= -1;
			}
			cont++;
		}
		else if (ft_isdigit((*bag)->summary[i]))
		{
			(*bag)->width = ((*bag)->width * 10) + ((*bag)->summary[i] - '0');
			cont++;
		}
		i++;
	}
	if (cont != 0)
		(*bag)->summary = (*bag)->summary + cont;
}
