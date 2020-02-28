/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 18:06:39 by jgalian-          #+#    #+#             */
/*   Updated: 2020/02/26 12:17:35 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	get_data_type(const char *format)
{
	int i;

	i = 1;
	while (!ft_isalpha(format[i]) && format[i] != '%' && format[i] != '\0')
		i++;
	return (format[i]);
}
