/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putchar_printf_.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 10:52:26 by ccardozo          #+#    #+#             */
/*   Updated: 2020/01/08 14:50:42 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	putchar_printf_1minus(int c, t_valores **bag)
{
	int		diff;

	diff = 0;
	ft_putchar(c);
	(*bag)->len += 1;
	if ((*bag)->width > 0)
		diff = (*bag)->width - 1;
	if (diff >= 0 && (*bag)->width > 0)
	{
		putspaces(diff);
		(*bag)->len += diff;
	}
}

static void	putchar_printf_0minus(int c, t_valores **bag)
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
	ft_putchar(c);
	(*bag)->len += 1;
}

void		putchar_printf(t_valores **bag)
{
	char	c;

	c = va_arg((*bag)->ap, int);
	if ((*bag)->menos == 1)
		putchar_printf_1minus(c, bag);
	else if ((*bag)->menos == 0)
		putchar_printf_0minus(c, bag);
}
