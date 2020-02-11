/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reinitialize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 13:52:13 by pcuadrad          #+#    #+#             */
/*   Updated: 2020/02/06 13:27:03 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		reinitialize(t_printf **bag)
{
	(*bag)->minus = 0;
	(*bag)->zero = 0;
	(*bag)->width = 0;
	(*bag)->width_aux = 0;
	(*bag)->precision = -1;
}
