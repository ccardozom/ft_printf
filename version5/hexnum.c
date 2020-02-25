/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexnum.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 12:08:26 by ccardozo          #+#    #+#             */
/*   Updated: 2020/02/24 15:10:40 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int		longofnum(long int n)
{
	int leng;

	leng = 0;
	if (n < 0)
	{
		leng++;
		n = n * -1;
	}
	while (n > 0)
	{
		n = n / 16;
		leng++;
	}
	return (leng);
}

static char		*inttochar(long int n, char *num, int leng)
{
	num[leng--] = '\0';
	if (n == 0)
		num[0] = 48;
	if (n < 0)
	{
		num[0] = '-';
		n = n * -1;
	}
	while (n > 0)
	{
		if (n % 16 <= 9)
			num[leng--] = 48 + (n % 16);
		else
			num[leng--] = 'W' + (n % 16);
		n = n / 16;
	}
	return (num);
}

char			*ft_itoahex(long n)
{
	char	*num;
	int		leng;

	leng = longofnum((long int)n);
	if (!n)
		leng = 1;
	if (!(num = (char *)malloc(sizeof(char) * (leng + 1))))
		return (NULL);
	return (num = inttochar((long int)n, num, leng));
}
