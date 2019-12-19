/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 09:57:11 by ccardozo          #+#    #+#             */
/*   Updated: 2019/12/19 14:42:47 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_printf(const	char *format, ...)
{
	int			len;
	valores		*bag;

	bag = new_ini(format);
	va_start(bag->ap, format);
	len = 0;
	if (bag->str[0] && bag->str[0] == '%' && !bag->str[1])
		;
	else if (!ft_strchr(bag->str, '%'))
		bag->len = bag->len + write(1, bag->str, ft_strlen(bag->str));
	else
		procesar_linea(&bag);
	len = bag->len;
	va_end(bag->ap);
	return (0);
}

int		main(void)
{
	int	i;
	int	j;
	int suma;

	i = 10;
	j = 5;
	suma = i + j;
	ft_printf("La suma de \" %d + %d es igual a %d", i, j, suma);
}
