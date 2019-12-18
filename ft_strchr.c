/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 12:15:05 by ccardozo          #+#    #+#             */
/*   Updated: 2019/12/18 10:25:01 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char		*ft_strchr(const char *s, int c)
{
	char	*p;
	int		i;

	p = (void *)s;
	i = 0;
	while (*p != c)
	{
		if (*p == '\0')
			return (NULL);
		p++;
	}
	return (p);
}
