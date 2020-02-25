/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 12:07:55 by ccardozo          #+#    #+#             */
/*   Updated: 2020/02/24 12:07:55 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static	int	flagone(t_printf *bag, int i, char *str)
{
	int aux;

	i++;
	if (str[i] != '*')
	{
		aux = i;
		while (ft_isdigit(str[aux]))
			aux++;
		bag->size = ft_atoi(ft_substr(str, i, aux));
		bag->leng += aux - i;
		i = i + (aux - i);
	}
	else
	{
		bag->size = va_arg(bag->valist, int);
		bag->leng += 2;
		i++;
	}
	if (bag->size < 0)
		bag->size *= -1;
	return (i);
}

static	int	flagtwo(t_printf *bag, int i, char *str)
{
	int aux;

	i++;
	if (str[i] != '*')
	{
		aux = i;
		while (ft_isdigit(str[aux]))
			aux++;
		bag->nprint = ft_atoi(ft_substr(str, i, aux));
		if (aux == i || bag->nprint == 0)
			bag->nprint = -1;
		bag->leng += aux - i + 1;
		i = i + (aux - i);
	}
	else
	{
		bag->nprint = va_arg(bag->valist, int);
		if (bag->nprint == 0)
		{
			bag->nast = -1;
			bag->nprint = -1;
		}
		bag->leng += 2;
	}
	return (i);
}

static	int	flagtre(t_printf *bag, int i, char *str, int aux)
{
	if (str[i + 1] != '-')
	{
		i++;
		if (str[i] != '*')
		{
			aux = i;
			while (ft_isdigit(str[aux]))
				aux++;
			bag->nzero = ft_atoi(ft_substr(str, i, aux));
			bag->leng += aux - i + 1;
			i = aux - 1;
		}
		else
		{
			bag->nzero = va_arg(bag->valist, int);
			bag->leng += 2;
		}
		if (bag->nzero < 0)
		{
			bag->size = bag->nzero * -1;
			bag->nzero = 0;
		}
	}
	return (i);
}

static	int	flagfour(t_printf *bag, int i, char *str)
{
	int aux;

	if (str[i] != '*')
	{
		aux = i;
		while (ft_isdigit(str[aux]))
			aux++;
		bag->rspace = ft_atoi(ft_substr(str, i, aux));
		bag->leng += aux - i + 1;
		i = i + (aux - i) - 1;
	}
	else
	{
		bag->rspace = va_arg(bag->valist, int);
		bag->leng += 2;
	}
	if (bag->rspace < 0)
	{
		bag->size = bag->rspace * -1;
		bag->rspace = 0;
	}
	return (i);
}

int			flagfive(t_printf *bag, int i, char *str)
{
	int aux;

	aux = 0;
	while (ft_isdigit(str[i]) || str[i] == '%'
			|| str[i] == '-' || str[i] == '.' || str[i] == '*')
	{
		i++;
		if (str[i] == '-')
			i = flagone(bag, i, str);
		if (str[i] == '.')
			i = flagtwo(bag, i, str);
		else if (str[i] == '0')
			i = flagtre(bag, i, str, aux);
		else if ((str[i] <= '9' && str[i] > '0') || str[i] == '*')
			i = flagfour(bag, i, str);
	}
	return (i);
}