/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 13:22:39 by ccardozo          #+#    #+#             */
/*   Updated: 2020/02/06 13:22:41 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	executer(t_printf **bag)
{
	if ((*bag)->conversion == 's')
		putstr_printf(bag);
	else if ((*bag)->conversion == 'c')
		putchar_printf(bag);
	else if ((*bag)->conversion == 'd' || (*bag)->conversion == 'i')
		putnbr_printf(bag);
	else if ((*bag)->conversion == 'u')
		putunsigned_printf(bag);
	else if ((*bag)->conversion == 'x' || (*bag)->conversion == 'X')
		puthex_printf(bag);
	else if ((*bag)->conversion == 'p')
		putmemory_printf(bag);
	else if ((*bag)->conversion == '%')
		putpercent_printf(bag);
}
