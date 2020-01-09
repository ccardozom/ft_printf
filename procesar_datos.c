/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   procesar_datos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 10:28:06 by ccardozo          #+#    #+#             */
/*   Updated: 2020/01/09 08:54:50 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	procesar_datos(t_valores **bag)
{
	if ((*bag)->conversion == 'd' || (*bag)->conversion == 'i')
		putnbr_printf(bag);
	else if ((*bag)->conversion == 'u')
		putunsigned_printf(bag);
	else if ((*bag)->conversion == 's')
		putstr_printf(bag);
	else if ((*bag)->conversion == 'c')
		putchar_printf(bag);
	else if ((*bag)->conversion == 'x' || (*bag)->conversion == 'X')
		puthex_printf(bag);
	else if ((*bag)->conversion == '%')
		putpercent_printf(bag);
	else if ((*bag)->conversion == 'p')
		putmemory_printf(bag);
}
