/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 08:45:10 by ccardozo          #+#    #+#             */
/*   Updated: 2020/01/09 08:54:28 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_putnstr(t_valores **bag, char *str)
{
	int		widthprecision;
	int		i;

	i = -1;
	if (!str)
		str = "(null)";
	widthprecision = (*bag)->precision;
	if (widthprecision != -1)
		while (str[++i] && widthprecision > 0)
		{
			(*bag)->len++;
			widthprecision--;
			ft_putchar(str[i]);
		}
	else
		while (str[++i])
		{
			(*bag)->len++;
			widthprecision--;
			ft_putchar(str[i]);
		}
	return (i);
}
