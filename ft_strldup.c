/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strldup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 10:42:30 by ccardozo          #+#    #+#             */
/*   Updated: 2020/01/09 12:22:16 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_strldup(char *format)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 1;
	while (format[i])
	{
		if (ft_strchr(SETS, format[i]))
			break ;
		i++;
		j++;
	}
	tmp = ft_substr(format, 0, j);
	return (tmp);
}
