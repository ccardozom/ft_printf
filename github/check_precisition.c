/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_precisition.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 13:20:39 by ccardozo          #+#    #+#             */
/*   Updated: 2020/02/06 13:20:46 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	check_precision(t_printf **bag)
{
	int		i;
	int		cont;

	i = -1;
	cont = 0;
	while ((*bag)->summary[++i])
		if ((*bag)->summary[i] == '.')
		{
			i++;
			cont++;
			(*bag)->precision = 0;
			if ((*bag)->summary[i] == '*')
			{
				if (((*bag)->precision = (int)va_arg((*bag)->argv, int)) < 0)
					(*bag)->precision = -1;
				cont++;
			}
			while (ft_isdigit((*bag)->summary[i]))
			{
				(*bag)->precision = ((*bag)->precision * 10)
				+ ((*bag)->summary[i++] - '0');
				cont++;
			}
		}
	(*bag)->summary = (*bag)->summary + cont;
}
