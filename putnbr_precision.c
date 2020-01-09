/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_precision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 10:47:12 by ccardozo          #+#    #+#             */
/*   Updated: 2020/01/09 08:55:25 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putnbrprintfprec(int nb, t_valores **bag)
{
	unsigned int	i;

	i = nb;
	if (nb < 0)
		i = i * -1;
	if (nb >= 10)
		ft_putnbrprintfprec(i / 10, bag);
	ft_putchar(i % 10 + '0');
	(*bag)->len += 1;
}
