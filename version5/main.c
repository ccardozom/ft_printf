/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 15:06:34 by ccardozo          #+#    #+#             */
/*   Updated: 2020/02/24 15:06:34 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int		main(int argc, char *argv[])
{
	int number = 5;
	char *pointer = "little";
	int a;
	int b;

	a = printf("Here is a number-%-100.34d-and a-%-10.20s-word.\n", number, pointer);
	printf("\n");
	b = ft_printf("Here is a number-%-100.34d-and a-%-10.20s-word.\n", number, pointer);
	printf("\nORIGINAL: %d -- TUYO: %d\n", a, b);
}
