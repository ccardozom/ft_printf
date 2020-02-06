/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 11:04:43 by pcuadrad          #+#    #+#             */
/*   Updated: 2020/02/06 13:23:46 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str_string;

	str_string = (char*)s;
	if (c == '\0')
	{
		while (*str_string)
			str_string++;
		return (str_string);
	}
	while (*str_string)
	{
		if (*str_string == (char)c)
			return (str_string);
		str_string++;
	}
	return (NULL);
}
