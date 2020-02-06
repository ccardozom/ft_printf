/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putzeros.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 14:15:23 by pcuadrad          #+#    #+#             */
/*   Updated: 2020/02/06 13:26:54 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	putzeros(int nzeros)
{
	if (nzeros > 0)
		while (nzeros)
		{
			ft_putchar('0');
			nzeros--;
		}
}
