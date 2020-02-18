/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 15:07:43 by pcuadrad          #+#    #+#             */
/*   Updated: 2020/02/06 13:23:08 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

size_t		ft_nbrlen(int num)
{
	size_t			size;
	unsigned int	nb;

	size = 0;
	nb = num;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		nb *= -1;
		size++;
	}
	while (nb > 0)
	{
		nb /= 10;
		size++;
	}
	return (size);
}

size_t		ft_nbrlenprec(int num)
{
	size_t			size;
	unsigned int	nb;

	size = 0;
	nb = num;
	if (num == 0)
		return (1);
	if (num < 0)
		nb *= -1;
	while (nb > 0)
	{
		nb /= 10;
		size++;
	}
	return (size);
}

size_t		ft_nbrulen(unsigned int num)
{
	size_t			size;
	unsigned int	nb;

	size = 0;
	nb = num;
	if (num == 0)
		return (1);
	while (nb > 0)
	{
		nb /= 10;
		size++;
	}
	return (size);
}
