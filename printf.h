#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# define SETS "cspdiuxX%"

typedef struct		ft_printf
{
	int		menos;
	int		zero;
	int		width;
	int		precision;
	char	conversion;
	va_list	ap;
	int		len;
	char	*str;
	char	*resul;
}					valores;

int					ft_printf(const char *format, ...);
int     eliminar(char *format, valores **bag);
int		ft_isdigit(int c);
char		*ft_strchr(const char *s, int c);
char	*ft_strldup(char *format);
size_t		ft_strlen(const char *str);
valores     *new_ini(const char *format);
void    procesar_linea(valores **bag);
void    reiniciar(valores **bag);
void    verificar_conversion(valores **bag);
void    verificar_flags(valores **bag);
void    verificar_precision(valores **bag);
void    verificar_width(valores **bag);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_putchar(char c);
void    procesar_datos(valores **bag);

#endif