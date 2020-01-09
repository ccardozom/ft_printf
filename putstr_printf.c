/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr_printf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 09:01:00 by ccardozo          #+#    #+#             */
/*   Updated: 2020/01/09 09:01:01 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static	int	putstr_printf_nonull_aux(int diff, int lenstr, t_valores **bag)
{
	if (diff > lenstr)
		diff += (*bag)->precision;
	else if (diff < lenstr)
		diff = (*bag)->width - (*bag)->precision;
	return (diff);
}

static void	putstr_printf_nonull(t_valores **bag, char *str)
{
	int		diff;
	int		lenstr;

	diff = 0;
	lenstr = (int)ft_strlen(str);
	if ((*bag)->width > lenstr && (*bag)->width != 0)
		diff = (*bag)->width - lenstr;
	else if ((*bag)->width < lenstr && (*bag)->width != 0)
		diff = lenstr - (*bag)->width;
	if (((*bag)->width > lenstr) ||
		((*bag)->width > (*bag)->precision && (*bag)->precision != -1))
	{
		if ((*bag)->precision > -1)
		{
			if (lenstr > (*bag)->precision && (*bag)->precision != 0)
				diff = putstr_printf_nonull_aux(diff, lenstr, bag);
			else if (lenstr > (*bag)->precision && (*bag)->precision == 0)
				diff = (*bag)->width;
		}
		if ((*bag)->zero)
			putzeros(diff);
		else
			putspaces(diff);
		(*bag)->len += diff;
	}
}

static void	putstr_printf_null(t_valores **bag)
{
	int diff;

	diff = 0;
	if ((*bag)->width > 6 && (*bag)->width != 0)
		diff = (*bag)->width - 6;
	else if ((*bag)->width < 6 && (*bag)->width != 0)
		diff = 6 - (*bag)->width;
	if (((*bag)->width > 6) ||
		((*bag)->width > (*bag)->precision && (*bag)->precision != -1))
	{
		if (6 > (*bag)->precision && (*bag)->precision > 0)
		{
			if (diff > 6)
				diff += (*bag)->precision;
			else if (diff < 6)
				diff = (*bag)->width - (*bag)->precision;
		}
		else if (6 > (*bag)->precision && (*bag)->precision == 0)
			diff = (*bag)->width;
		if ((*bag)->zero)
			putzeros(diff);
		else
			putspaces(diff);
		(*bag)->len += diff;
	}
}

void		putstr_printf(t_valores **bag)
{
	int		diff;
	char	*str;

	diff = 0;
	str = va_arg((*bag)->ap, char*);
	if ((*bag)->menos == 1)
	{
		diff = ft_putnstr(bag, str);
		if ((*bag)->width > 0)
			diff = (*bag)->width - diff;
		if (diff >= 0 && (*bag)->width > 0)
		{
			putspaces(diff);
			(*bag)->len += diff;
		}
	}
	else if ((*bag)->menos == 0)
	{
		if (str)
			putstr_printf_nonull(bag, str);
		else
			putstr_printf_null(bag);
		ft_putnstr(bag, str);
	}
}
