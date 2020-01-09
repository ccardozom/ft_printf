/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putmemory_printf_au.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 14:21:33 by ccardozo          #+#    #+#             */
/*   Updated: 2020/01/08 14:51:21 by ccardozo         ###   ########.fr       */
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

void		putmemory_nill(t_valores **bag)
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
			(*bag)->len += diff;
		}
	}
	diff = 1;
	if ((*bag)->precision != -1)
		diff = (*bag)->precision;
	printf_0x(bag);
	putzeros(diff);
	(*bag)->len += diff;
}

void		ft_putnbr_base_mem(t_uintptr nb, char *str, t_valores **bag)
{
	if (nb >= 16)
		ft_putnbr_base_mem(nb / 16, str, bag);
	ft_putchar(str[nb % 16]);
	(*bag)->len++;
}

void		printf_0x(t_valores **bag)
{
	write(1, "0x", 2);
	(*bag)->len += 2;
}