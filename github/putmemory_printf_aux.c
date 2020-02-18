/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putmemory_printf_aux.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 19:31:13 by pcuadrad          #+#    #+#             */
/*   Updated: 2020/02/06 13:25:40 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

size_t		ft_nbrmemlen(t_uintptr num)
{
	size_t			size;

	size = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num /= 16;
		size++;
	}
	return (size);
}

void		putmemory_nill(t_printf **bag)
{
	int		diff;

	if ((*bag)->width > 1)
	{
		if ((*bag)->precision > 1)
			diff = (*bag)->width - (*bag)->precision - 2;
		else if ((*bag)->precision == -1)
			diff = (*bag)->width - 3;
		else
			diff = (*bag)->width - 2;
		if (diff > 0)
		{
			putspaces(diff);
			(*bag)->size += diff;
		}
	}
	diff = 1;
	if ((*bag)->precision != -1)
		diff = (*bag)->precision;
	printf_0x(bag);
	putzeros(diff);
	(*bag)->size += diff;
}

void		ft_putnbr_base_mem(t_uintptr nb, char *str, t_printf **bag)
{
	if (nb >= 16)
		ft_putnbr_base_mem(nb / 16, str, bag);
	ft_putchar(str[nb % 16]);
	(*bag)->size++;
}

void		printf_0x(t_printf **bag)
{
	write(1, "0x", 2);
	(*bag)->size += 2;
}
