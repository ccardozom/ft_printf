/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eliminar_.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 09:04:29 by ccardozo          #+#    #+#             */
/*   Updated: 2020/01/09 12:21:58 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		eliminar(char *format, t_valores **bag)
{
	int		len;

	(*bag)->resul = ft_strldup(format);
	len = ft_strlen((*bag)->resul);
	verificar_flags(bag);
	verificar_width(bag);
	verificar_precision(bag);
	verificar_conversion(bag);
	procesar_datos(bag);
	return (len);
}
