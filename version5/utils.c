/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 12:09:33 by ccardozo          #+#    #+#             */
/*   Updated: 2020/02/24 15:10:29 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strupcase(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 32;
		++i;
	}
	return (str);
}

void	flagnaux(t_printf *bag, char *printstr, int neg, int lng)
{
	if (bag->nzero > 0)
		bag->nzero -= lng;
	if (bag->nprint > lng)
	{
		bag->nzero += bag->nprint - lng + neg;
		bag->nprint = 0;
	}
	if (bag->nprint > 0)
		bag->nprint = 0;
	if (bag->size > 0 && bag->nzero > 0)
		bag->size -= bag->nzero;
	if (bag->rspace > 0 && bag->nzero > 0)
		bag->rspace -= bag->nzero;
	if (bag->nast == -1 && bag->rspace > 0)
		bag->rspace++;
	if (bag->nast == -1 && bag->size > 0)
		bag->size++;
	if (bag->nast == -1 && bag->nprint == -1)
		bag->nprint = 0;
	regulbag(bag, printstr);
}

void	flagn(t_printf *bag, char *printstr)
{
	int	neg;
	int	lng;

	lng = ft_strlen(printstr);
	neg = 0;
	if (printstr[0] == '-')
		neg = 1;
	if (bag->nzero > 0 && bag->nprint > 0)
	{
		bag->rspace = bag->nzero - bag->nprint;
		bag->nzero = bag->nzero - bag->rspace - lng + neg;
		if (bag->nzero < 0)
			bag->nzero = 0;
		bag->rspace += bag->nprint - bag->nzero;
		bag->nprint = 0;
		regulbag(bag, printstr);
		return ;
	}
	flagnaux(bag, printstr, neg, lng);
}

int		printfo(char *str, t_printf *bag, int n)
{
	char *printstr;

	if (*str == 's')
	{
		getflag(bag, str - 1 - n);
		printstr = va_arg(bag->valist, char*);
		if (!printstr)
			printstr = ft_strdup("(null)");
		if (bag->nzero > 0)
			bag->nzero -= ft_strlen(printstr);
		regulbag(bag, printstr);
		if (bag->nprint == -1)
			return (0);
		if ((ft_strlen(printstr) >= (size_t)bag->nprint
			&& bag->nprint != 0))
		{
			ft_putstr_fd(ft_substr(printstr, 0, bag->nprint), 1);
			return (bag->nprint);
		}
		else
			ft_putstr_fd(printstr, 1);
		return (ft_strlen(printstr));
	}
	return (0);
}

int		printfi(char *str, t_printf *bag, int n)
{
	char	*printstr;
	int		printint;

	if (*str == 'i' || *str == 'd')
	{
		getflag(bag, str - 1 - n);
		printint = va_arg(bag->valist, int);
		printstr = ft_strdup(ft_itoa(printint));
		flagn(bag, printstr);
		if (bag->nprint == -1)
			return (0);
		if (bag->nast == -1 && printint == 0)
			return (0);
		if (printstr[0] == '-' && bag->nzero == 1)
			ft_putstr_fd(printstr + 1, 1);
		else
			ft_putstr_fd(printstr, 1);
		return (ft_strlen(printstr));
	}
	return (0);
}
