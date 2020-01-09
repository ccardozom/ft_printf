/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verificar_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 09:01:19 by ccardozo          #+#    #+#             */
/*   Updated: 2020/01/09 15:25:02 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int espacios(char *str)
{
	char *p;
	int add;
	int i;
	
	p = (void*)str;
	i = -1;
	add = 0;
	while (*p && *p >= '0' && *p <= '9')
	{
		add = add * 10 + ((int)*p - 48);
		p++;
	}
	return (add);
}

void	verificar_flags(t_valores **bag)
{
	int	i;
	int	cont;

	i = -1;
	cont = 0;
	while ((*bag)->resul[++i] && (*bag)->resul[i] != '.')
	{
		if ((*bag)->resul[i] == '-')
		{
			(*bag)->menos = 1;
			cont++;
		}
		if ((*bag)->resul[i] == '0' && ((!ft_isdigit((*bag)->resul[i - 1])
			&& (*bag)->resul[i - 1] != '.') || (*bag)->resul[i - 1] == '0'))
		{
			(*bag)->zero = 1;
			cont++;
		}
		
		if ((*bag)->resul[i] >= '1' && (*bag)->resul[i] <= '9')
			(*bag)->aux = espacios((*bag)->resul);
	}
	if (cont != 0)
		(*bag)->resul = (*bag)->resul + cont;
}
