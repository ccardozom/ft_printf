/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 12:07:16 by ccardozo          #+#    #+#             */
/*   Updated: 2020/02/24 15:10:35 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft/libft.h"
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# define ULINT_MAX (4294967295)

typedef struct		s_printf
{
	va_list	valist;
	int		size;
	int		rspace;
	int		nprint;
	int		nzero;
	int		leng;
	int		multi;
	int		nast;
	int		nast2;
	int		lenght;
}					t_printf;
char				*ft_itoaioctal(int n);
int					ft_printf(const char *str, ...);
char				*ft_itoaun(unsigned int n);
char				*ft_itoahex(long n);
char				*ft_itoamem(unsigned long n);
void				getflag(t_printf *bag, char *str);
void				bagzero(t_printf *bag);
char				*next(char *str, t_printf *bag);
int					getvar(char *str);
void				regulbag(t_printf *bag, char *str);
void				getastvar(const char *str, t_printf *bag);
char				*ft_strupcase(char *str);
void				flagn(t_printf *bag, char *printstr);
void				regulbagn(t_printf *bag, char *str);
void				regulbags(t_printf *bag, char *str);
int					flagfive(t_printf *bag, int i, char *str);
int					printfi(char *str, t_printf *bag, int n);
int					printfo(char *str, t_printf *bag, int n);
void				flagn(t_printf *bag, char *printstr);
void				flagnaux(t_printf *bag, char *printstr, int neg, int lng);
int					printsev(char *printstr, t_printf *bag, int i);
int					printsix(char *str, t_printf *bag, int n);
int					printone(char *str, t_printf *bag, int n);
int					printlol(char *str, t_printf *bag, int n);
int					printtwo(char *str, t_printf *bag, int n);
int					printthree(char *str, t_printf *bag, int n);
char				*printpls(t_printf *bag, char *str, int n);
int					printall(char *str, t_printf *bag);
#endif
