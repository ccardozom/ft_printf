/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsgint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 12:09:24 by ccardozo          #+#    #+#             */
/*   Updated: 2020/02/24 15:10:26 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int		longofnum(unsigned int n)
{
	int leng;

	leng = 0;
	while (n > 0)
	{
		n = n / 10;
		leng++;
	}
	return (leng);
}

static char		*inttochar(unsigned int n, char *num, int leng)
{
	num[leng--] = '\0';
	if (n == 0)
		num[0] = 48;
	while (n > 0)
	{
		num[leng--] = 48 + (n % 10);
		n = n / 10;
	}
	return (num);
}

char			*ft_itoaun(unsigned int n)
{
	char	*num;
	int		leng;

	leng = longofnum(n);
	if (!n)
		leng = 1;
	if (!(num = (char *)malloc(sizeof(char) * (leng + 1))))
		return (NULL);
	return (num = inttochar(n, num, leng));
}

int				printlol(char *str, t_printf *bag, int n)
{
	unsigned int unint;

	if (*str == 'c')
	{
		getflag(bag, str - 1 - n);
		unint = va_arg(bag->valist, int);
		regulbag(bag, "c");
		if (bag->nprint == -1)
			return (0);
		ft_putchar_fd((int)unint, 1);
		return (1);
	}
	return (0);
}
