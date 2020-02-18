/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putspaces.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 17:34:35 by pcuadrad          #+#    #+#             */
/*   Updated: 2020/02/06 13:26:24 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	putspaces(int nspaces)
{
	if (nspaces)
		while (nspaces > 0)
		{
			ft_putchar(' ');
			nspaces--;
		}
}
