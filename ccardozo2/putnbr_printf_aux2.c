/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_printf_aux2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 15:33:35 by pcuadrad          #+#    #+#             */
/*   Updated: 2020/02/06 13:26:03 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	putnbr_print_0_aux(t_printf **bag, int *diff)
{
	if ((*bag)->precision > 0)
	{
		*diff = (*bag)->precision;
		putzeros(*diff);
		(*bag)->size += *diff;
	}
}

void		putnbr_print_0(t_printf **bag)
{
	int		diff;

	diff = 0;
	if ((*bag)->minus == 1)
	{
		putnbr_print_0_aux(bag, &diff);
		putnbr_width_prec(bag, diff, 0);
	}
	else
	{
		putnbr_width_prec(bag, diff, 0);
		putnbr_print_0_aux(bag, &diff);
	}
}

void		ft_putnbrprintfprec(int nb, t_printf **bag)
{
	unsigned int	i;

	i = nb;
	if (nb < 0)
		i = i * -1;
	if (i >= 10)
		ft_putnbrprintfprec(i / 10, bag);
	ft_putchar(i % 10 + '0');
	(*bag)->size += 1;
}

void		ft_putnbrprintf(int nb, t_printf **bag)
{
	unsigned int	i;

	i = nb;
	if (nb < 0)
	{
		ft_putchar('-');
		i = i * -1;
		(*bag)->size += 1;
	}
	if (i >= 10)
		ft_putnbrprintf(i / 10, bag);
	ft_putchar(i % 10 + '0');
	(*bag)->size += 1;
}

void		ft_putnbr_base(int nb, char *str, t_printf **bag)
{
	unsigned int	nbr;

	nbr = nb;
	if (nbr >= 16)
		ft_putnbr_base(nbr / 16, str, bag);
	ft_putchar(str[nbr % 16]);
	(*bag)->size++;
}
