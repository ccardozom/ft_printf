/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 12:08:08 by ccardozo          #+#    #+#             */
/*   Updated: 2020/02/24 15:09:01 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	getflag(t_printf *bag, char *str)
{
	int i;
	int count;

	count = 0;
	bag->leng = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == '%')
				break ;
			count++;
			i = flagfive(bag, i, str);
		}
		i++;
		if (count >= 1)
			break ;
	}
}
