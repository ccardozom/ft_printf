/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 13:20:31 by ccardozo          #+#    #+#             */
/*   Updated: 2020/02/06 13:20:33 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	check_flags(t_printf **bag)
{
	int		i;
	int		cont;

	i = -1;
	cont = 0;
	while ((*bag)->summary[++i] && (*bag)->summary[i] != '.')
	{
		if ((*bag)->summary[i] == '-')
		{
			(*bag)->minus = 1;
			cont++;
		}
		if ((*bag)->summary[i] == '0' && ((!ft_isdigit((*bag)->summary[i - 1])
			&& (*bag)->summary[i - 1] != '.') || (*bag)->summary[i - 1] == '0'))
		{
			(*bag)->zero = 1;
			cont++;
		}
	}
	if (cont != 0)
		(*bag)->summary = (*bag)->summary + cont;
}
