/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destructor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 13:21:05 by ccardozo          #+#    #+#             */
/*   Updated: 2020/02/06 13:21:13 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		destructor(char *format, t_printf **bag)
{
	int		size;

	(*bag)->summary = ft_strldup(format);
	size = ft_strlen((*bag)->summary);
	check_flags(bag);
	check_width(bag);
	check_precision(bag);
	check_conversion(bag);
	executer(bag);
	return (size);
}
