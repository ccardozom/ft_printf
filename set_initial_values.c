/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_initial_values.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 19:22:14 by jgalian-          #+#    #+#             */
/*   Updated: 2020/02/26 12:19:04 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	set_initial_values(t_var *var)
{
	var->printed_chars_counter = 0;
	var->str_pos = 0;
	var->data_type = ' ';
	var->minus = 0;
	var->zero = 0;
	var->point = 0;
	var->width = 0;
	var->precision = 0;
	var->precision_value = 0;
	var->spaces = 0;
	var->zero_pad = 0;
}
