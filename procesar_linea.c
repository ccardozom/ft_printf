/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   procesar_linea.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 10:30:08 by ccardozo          #+#    #+#             */
/*   Updated: 2020/01/09 08:45:35 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	procesar_linea(t_valores **bag)
{
	int i;

	i = -1;
	while ((*bag)->str[++i])
	{
		if ((*bag)->str[i] == '%')
		{
			reiniciar(bag);
			i = i + eliminar((*bag)->str + i + 1, bag);
		}
		else
			(*bag)->len = (*bag)->len + write(1, &(*bag)->str[i], 1);
	}
}
