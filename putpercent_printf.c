/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putpercent_printf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 12:42:59 by ccardozo          #+#    #+#             */
/*   Updated: 2020/01/09 08:56:16 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	putpercent_printf_1minus(t_valores **bag)
{
	int		diff;

	diff = 0;
	ft_putchar('%');
	(*bag)->len += 1;
	if ((*bag)->width > 0)
		diff = (*bag)->width - 1;
	if (diff >= 0 && (*bag)->width > 0)
	{
		putspaces(diff);
		(*bag)->len += diff;
	}
}

static void	putpercent_printf_0minus(t_valores **bag)
{
	int		diff;

	diff = 0;
	if ((*bag)->width > 0)
		diff = (*bag)->width - 1;
	if (diff >= 0 && (*bag)->width > 0)
	{
		putspaces(diff);
		(*bag)->len += diff;
	}
	ft_putchar('%');
	(*bag)->len += 1;
}

static void	putpercent_printf_zeros(t_valores **bag)
{
	int		diff;

	diff = 0;
	if ((*bag)->width > 0)
		diff = (*bag)->width - 1;
	if (diff >= 0 && (*bag)->width > 0)
	{
		putzeros(diff);
		(*bag)->len += diff;
	}
	ft_putchar('%');
	(*bag)->len += 1;
}

void		putpercent_printf(t_valores **bag)
{
	if ((*bag)->menos == 1)
		putpercent_printf_1minus(bag);
	else if ((*bag)->menos == 0)
	{
		if ((*bag)->zero == 1)
			putpercent_printf_zeros(bag);
		else
			putpercent_printf_0minus(bag);
	}
}