/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_base_.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 10:43:22 by ccardozo          #+#    #+#             */
/*   Updated: 2020/01/08 14:51:29 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putnbr_base(int nb, char *str, t_valores **bag)
{
	unsigned int	nbr;

	nbr = nb;
	if (nbr >= 16)
		ft_putnbr_base(nbr / 16, str, bag);
	ft_putchar(str[nbr % 16]);
	(*bag)->len++;
}
