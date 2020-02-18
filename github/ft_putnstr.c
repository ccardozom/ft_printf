/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 14:25:40 by pcuadrad          #+#    #+#             */
/*   Updated: 2020/02/06 13:23:37 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_putnstr(t_printf **bag, char *str)
{
	int		widthprecision;
	int		i;

	i = 0;
	if (!str)
		str = "(null)";
	widthprecision = (*bag)->precision;
	if (widthprecision != -1)
		while (str[i] && widthprecision > 0)
		{
			(*bag)->size++;
			widthprecision--;
			ft_putchar(str[i]);
			i++;
		}
	else
		while (str[i])
		{
			(*bag)->size++;
			widthprecision--;
			ft_putchar(str[i]);
			i++;
		}
	return (i);
}
