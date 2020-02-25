/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointmem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 12:09:09 by ccardozo          #+#    #+#             */
/*   Updated: 2020/02/24 15:10:18 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"

static int	get_digits(long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}

char		*ft_itoamem(unsigned long n)
{
	int		digits;
	long	numb;
	char	*str;

	numb = n;
	digits = get_digits(numb);
	if (!(str = malloc((digits + 4) * sizeof(char))))
		return (NULL);
	str[digits--] = '\0';
	if (numb == 0)
		str[0] = '0';
	while (numb > 0)
	{
		if (numb % 16 <= 9)
			str[digits] = numb % 16 + '0';
		else if (numb % 16 < 16)
			str[digits] = numb % 16 + 'W';
		numb /= 16;
		digits--;
	}
	return (ft_strjoin("0x", str));
}

int			printsev(char *printstr, t_printf *bag, int i)
{
	if (bag->nzero > 0)
	{
		printstr = ft_substr(printstr, 2, ft_strlen(printstr));
		i += bag->nzero + 1;
	}
	if (bag->nprint == -1)
		return (0);
	ft_putstr_fd(printstr, 1);
	return (ft_strlen(printstr) + i);
}

int			printsix(char *str, t_printf *bag, int n)
{
	unsigned long	unlong;
	char			*printstr;
	int				i;

	if (*str == 'p')
	{
		i = 0;
		getflag(bag, str - 1 - n);
		unlong = va_arg(bag->valist, unsigned long);
		printstr = ft_strdup(ft_itoamem(unlong));
		if (bag->nprint > 0)
			bag->nprint += 2;
		if (bag->nprint == -1)
		{
			printstr = ft_strdup("0x");
			bag->nprint = 2;
		}
		flagn(bag, printstr);
		return (printsev(printstr, bag, i));
	}
	return (0);
}

int			printone(char *str, t_printf *bag, int n)
{
	if (*str == '%')
	{
		getflag(bag, str - 1 - n);
		if (bag->nzero > 0)
			bag->nzero--;
		regulbag(bag, "%");
		if (bag->nprint == -1)
			return (0);
		ft_putchar_fd('%', 1);
		return (1);
	}
	return (0);
}
