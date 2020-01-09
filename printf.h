/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 14:55:01 by ccardozo          #+#    #+#             */
/*   Updated: 2020/01/09 14:24:18 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# define SETS "cspdiuxX%"
# define HEX "123456789abcdf"

typedef __UINTPTR_TYPE__	t_uintptr;
typedef struct	s_valores
{
	int			menos;
	int			zero;
	int			width;
	int			precision;
	int			aux;
	char		conversion;
	va_list		ap;
	int			len;
	char		*str;
	char		*resul;
	
}				t_valores;

int				ft_printf(const char *format, ...);
int				eliminar(char *format, t_valores **bag);
int				ft_isdigit(int c);
char			*ft_strchr(const char *s, int c);
char			*ft_strldup(char *format);
size_t			ft_strlen(const char *str);
t_valores		*new_ini(const char *format);
void			procesar_linea(t_valores **bag);
void			reiniciar(t_valores **bag);
void			verificar_conversion(t_valores **bag);
void			verificar_flags(t_valores **bag);
void			verificar_precision(t_valores **bag);
void			verificar_width(t_valores **bag);
char			*ft_substr(char const *s, unsigned int start, size_t len);
void			ft_putchar(char c);
void			procesar_datos(t_valores **bag);
void			putspaces(int nspaces);
void			putnbr_printf_zero(t_valores **bag);
void			putnbr_printf_menos1(t_valores **bag);
void			putnbr_printf_0(t_valores **bag);
void			putnbr_auxiliar_0_printf(t_valores **bag, int *diff);
void			putnbr_printf(t_valores **bag);
void			putzeros(int nzeros);
void			ft_putnbrprintfprec(int nb, t_valores **bag);
void			putnbr_prec_len(t_valores **bag, int len);
size_t			ft_nbrulen(unsigned int num);
size_t			ft_nbrlenprec(int num);
size_t			ft_nbrlen(int num);
int				putnbr_check_zero(t_valores **bag);
void			putnbr_width_prec(t_valores **bag, int len, int neg);
void			putnbr_printf_menos0(t_valores **bag);
void			ft_putnbrprintf(int nb, t_valores **bag);
void			putnbr_printf_precision(t_valores **bag);
void			putunsigned_printf(t_valores **bag);
void			ft_putnbru(unsigned int nb, t_valores **bag);
unsigned int	putunsigned_check_zero(t_valores **bag);
void			putnbr_width_zeros(t_valores **bag, int len, int neg);
int				ft_putnstr(t_valores **bag, char *str);
void			putnbr_printf_precision(t_valores **bag);
void			putnbr_printf_zeros(t_valores **bag);
void			printf_0x(t_valores **bag);
void			ft_putnbr_base_mem(t_uintptr nb, char *str, t_valores **bag);
void			putmemory_nill(t_valores **bag);
size_t			ft_nbrmemlen(t_uintptr num);
void			printf_hex(int number, t_valores **bag);
void			ft_putnbr_base(int nb, char *str, t_valores **bag);
size_t			ft_nbrhexlen(int num);
void			putmemory_printf(t_valores **bag);
void			puthex_printf(t_valores **bag);
void			putpercent_printf(t_valores **bag);
void			putchar_printf(t_valores **bag);
void			putstr_printf(t_valores **bag);
#endif
