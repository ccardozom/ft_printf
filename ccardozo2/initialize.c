/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 13:48:20 by pcuadrad          #+#    #+#             */
/*   Updated: 2020/02/06 13:24:42 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_printf	*initilialize(const char *format)
{
	t_printf	*new_bag;

	if (!(new_bag = malloc(sizeof(t_printf))))
		return (NULL);
	new_bag->format = (char *)format;
	new_bag->size = 0;
	return (new_bag);
}
