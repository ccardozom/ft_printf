/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 12:21:54 by pcuadrad          #+#    #+#             */
/*   Updated: 2020/02/06 13:27:29 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			ft_printf(const char *format, ...)
{
	int			size;
	t_printf	*bag;

	bag = initilialize(format);
	va_start(bag->argv, format);
	size = 0;
	if (bag->format[0] && bag->format[0] == '%' && !bag->format[1])
		;
	else if (!ft_strchr(bag->format, '%'))
		bag->size += write(1, bag->format, ft_strlen(bag->format));
	else
		processline(&bag);
	size = bag->size;
	va_end(bag->argv);
	return (size);
}
