/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verificar_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 15:00:11 by ccardozo          #+#    #+#             */
/*   Updated: 2020/01/08 15:01:16 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	verificar_width(t_valores **bag)
{
	int i;
	int cont;

	i = 0;
	cont = 0;
	while ((*bag)->resul[++i] && (*bag)->resul[i] != '.')
	{
		if ((*bag)->resul[i] == '*')
		{
			if (((*bag)->width = (int)va_arg((*bag)->ap, int)) < 0)
			{
				(*bag)->menos = 1;
				(*bag)->width = (*bag)->width * -1;
			}
			cont++;
		}
		else if (ft_isdigit((*bag)->resul[i]))
		{
			(*bag)->width = ((*bag)->width * 10) + ((*bag)->resul[i] - '0');
			cont++;
		}
		i++;
	}
	if (cont != 0)
		(*bag)->resul = (*bag)->resul + cont;
}
