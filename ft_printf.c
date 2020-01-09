/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 09:57:11 by ccardozo          #+#    #+#             */
/*   Updated: 2020/01/09 15:20:07 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_printf(const	char *format, ...)
{
	int			len;
	t_valores		*bag;

	bag = new_ini(format);
	va_start(bag->ap, format);
	len = 0;
	if (bag->str[0] && bag->str[0] == '%' && !bag->str[1])
		write(1, "Incomplete format specifier", 28);
	else if (!ft_strchr(bag->str, '%'))
		write(1, bag->str, ft_strlen(bag->str));
	else
		procesar_linea(&bag);
	len = bag->len;
	va_end(bag->ap);
	free(bag);
	return (len);
}

int	main(void)
{
	int	i;
	float j;
	double m;
	
	
	i = 25012;
	j = 15.45114;
	m = 15.541541;


	ft_printf("%97i", 33);
	printf("%7i", 33);
	//printf("\n%X",j);
}
