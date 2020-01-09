/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verificar_precision.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 09:03:57 by ccardozo          #+#    #+#             */
/*   Updated: 2020/01/09 09:15:44 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		precision_auxiliar(t_valores **bag, int cont)
{
	if (((*bag)->precision = (int)va_arg((*bag)->ap, int)) < 0)
		(*bag)->precision = -1;
	return (cont++);
}

void	verificar_precision(t_valores **bag)
{
	int i;
	int cont;

	i = -1;
	cont = 0;
	while ((*bag)->resul[++i])
	{
		if ((*bag)->resul[i] == '.')
		{
			i++;
			cont++;
			(*bag)->precision = 0;
			if ((*bag)->resul[i] == '*')
				cont = precision_auxiliar(bag, cont);			
			while (ft_isdigit((*bag)->resul[i]))
			{
				(*bag)->precision = ((*bag)->precision * 10)
					+ ((*bag)->resul[i++] - '0');
				cont++;
			}
		}
	}
	(*bag)->resul = (*bag)->resul + cont;
}
