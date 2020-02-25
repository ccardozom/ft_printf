/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spaces.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 12:09:16 by ccardozo          #+#    #+#             */
/*   Updated: 2020/02/24 15:10:23 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void			bagzero(t_printf *bag)
{
	bag->size = 0;
	bag->rspace = 0;
	bag->nprint = 0;
	bag->nzero = 0;
	bag->leng = 0;
	bag->multi = 0;
	bag->nast = 0;
	bag->nast2 = 0;
}

char			*next(char *str, t_printf *bag)
{
	while (bag->leng-- > 0)
		str++;
	return (str);
}

int				getvar(char *str)
{
	int i;

	i = 0;
	while (*str == '-' || *str == '.' || *str == '*' || ft_isdigit(*str))
	{
		str++;
		i++;
	}
	return (i);
}

static	void	helpme(t_printf *bag, char *str)
{
	if (bag->nzero > 0)
	{
		if (str[0] == '-')
			ft_putchar_fd('-', 1);
		if (str[0] == '0' && str[1] == 'x')
			ft_putstr_fd("0x", 1);
		while (bag->nzero-- > 0)
		{
			ft_putchar_fd('0', 1);
			bag->lenght++;
		}
		bag->nzero = 1;
	}
}

void			regulbag(t_printf *bag, char *str)
{
	if (bag->size > 0 && bag->nprint == -1)
		return ;
	else if (bag->size > 0 && bag->nprint > 0
			&& (size_t)bag->nprint < ft_strlen(str))
		bag->size = bag->size - bag->nprint;
	else if (bag->size > 0)
		bag->size = bag->size - ft_strlen(str);
	if (bag->nprint > 0 && bag->rspace > 0
			&& (size_t)bag->nprint < ft_strlen(str))
		bag->rspace = bag->rspace - bag->nprint;
	else if (bag->rspace > 0 && bag->nprint != -1)
		bag->rspace = bag->rspace - ft_strlen(str);
	if (bag->rspace > 0)
	{
		while (bag->rspace-- > 0)
		{
			ft_putchar_fd(32, 1);
			bag->lenght++;
		}
	}
	helpme(bag, str);
}
