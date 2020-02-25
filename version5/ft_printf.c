/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 12:07:39 by ccardozo          #+#    #+#             */
/*   Updated: 2020/02/24 15:09:04 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		printtwo(char *str, t_printf *bag, int n)
{
	char			*printstr;
	unsigned int	unint;

	if (*str == 'u')
	{
		getflag(bag, str - 1 - n);
		unint = va_arg(bag->valist, unsigned int);
		printstr = ft_strdup(ft_itoaun(unint));
		flagn(bag, printstr);
		if (bag->nprint == -1)
			return (0);
		ft_putstr_fd(printstr, 1);
		return (ft_strlen(printstr));
	}
	return (0);
}

int		printthree(char *str, t_printf *bag, int n)
{
	char			*printstr;
	unsigned int	printlen;

	if (*str == 'x' || *str == 'X')
	{
		getflag(bag, str - 1 - n);
		printlen = va_arg(bag->valist, unsigned int);
		if (printlen < 0)
			printlen = ULINT_MAX - printlen;
		printstr = ft_strdup(ft_itoahex(printlen));
		if (*str == 'X')
			printstr = ft_strupcase(printstr);
		flagn(bag, printstr);
		if (bag->nprint == -1)
			return (0);
		ft_putstr_fd(printstr, 1);
		return (ft_strlen(printstr));
	}
	return (0);
}

char	*printpls(t_printf *bag, char *str, int n)
{
	str++;
	bagzero(bag);
	n = getvar(str);
	str = str + n;
	bag->lenght += printone(str, bag, n);
	bag->lenght += printtwo(str, bag, n);
	bag->lenght += printthree(str, bag, n);
	bag->lenght += printfo(str, bag, n);
	bag->lenght += printfi(str, bag, n);
	bag->lenght += printsix(str, bag, n);
	bag->lenght += printlol(str, bag, n);
	if (*str == 's' || *str == 'c' || *str == 'p' || *str == 'd' || *str == 'i'
		|| *str == 'u' || *str == 'x' || *str == 'X' || *str == '%')
		str++;
	if (bag->size != 0)
	{
		while (bag->size-- > 0)
		{
			ft_putchar_fd(32, 1);
			bag->lenght++;
		}
	}
	return (str);
}

int		printall(char *str, t_printf *bag)
{
	int	n;

	n = 0;
	bag->lenght = 0;
	while (*str)
	{
		if (*str == '%')
			str = printpls(bag, str, n);
		else
		{
			ft_putchar_fd(*str, 1);
			str++;
			bag->lenght++;
		}
	}
	va_end(bag->valist);
	return (bag->lenght);
}

int		ft_printf(const char *str, ...)
{
	int				result;
	t_printf			*bag;

	if (!str)
		return (0);
	if (!(bag = malloc(sizeof(*bag))))
		return (-1);
	va_start(bag->valist, str);
	bagzero(bag);
	result = printall((char *)str, bag);
	va_end(bag->valist);
	free(bag);
	return (result);
}