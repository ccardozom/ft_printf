/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_ini.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 09:33:07 by ccardozo          #+#    #+#             */
/*   Updated: 2020/01/09 08:54:42 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_valores		*new_ini(const char *format)
{
	t_valores *new_bag;

	if (!(new_bag = malloc(sizeof(t_valores))))
		return (NULL);
	new_bag->str = (char *)format;
	new_bag->len = 0;
	return (new_bag);
}
