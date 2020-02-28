/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_caracter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 18:52:45 by jgalian-          #+#    #+#             */
/*   Updated: 2020/02/26 12:18:07 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_caracter(t_var *var)
{
	if (var->width > 1)
	{
		var->spaces = var->width - 1;
		if (var->minus == 1)
		{
			ft_putchar_fd(va_arg(var->args, int), 1);
			print_spaces(var);
		}
		else
		{
			print_spaces(var);
			ft_putchar_fd(va_arg(var->args, int), 1);
		}
	}
	else
		ft_putchar_fd(va_arg(var->args, int), 1);
	var->printed_chars_counter++;
	var->str_pos++;
}
