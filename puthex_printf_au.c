/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puthex_printf_au.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 11:00:33 by ccardozo          #+#    #+#             */
/*   Updated: 2020/01/08 14:50:49 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		printf_hex(int number, t_valores **bag)
{
	if ((*bag)->conversion == 'x')
		ft_putnbr_base(number, "0123456789abcdef", bag);
	else
		ft_putnbr_base(number, "0123456789ABCDEF", bag);
}

size_t		ft_nbrhexlen(int num)
{
	size_t			size;
	unsigned int	nb;

	size = 0;
	nb = num;
	if (num == 0)
		return (1);
	while (nb > 0)
	{
		nb /= 16;
		size++;
	}
	return (size);
}
