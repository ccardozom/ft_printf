/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verificar_conversion.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 09:02:36 by ccardozo          #+#    #+#             */
/*   Updated: 2020/01/09 09:02:42 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	verificar_conversion(t_valores **bag)
{
	int	i;

	i = 0;
	(*bag)->conversion = (*bag)->resul[i];
}
