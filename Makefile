NAME = libftprintf.a

CFLAGS = -Wall -Werror -Wextra

LFLAGS = -c

FILES = 	eliminar_.c ft_isdigit.c ft_nbr.c ft_printf.c ft_putchar.c ft_putnstr.c ft_strchr.c ft_strldup.c \
ft_strlen.c ft_substr.c new_ini.c procesar_datos.c procesar_linea.c putchar_printf_.c puthex_printf_au.c puthex_printf.c \
putmemory_printf_.c putmemory_printf_au.c putnbr_auxiliar_0_printf.c putnbr_base_.c putnbr_check_zero.c putnbr_precision_len.c \
putnbr_precision.c putnbr_printf_0.c putnbr_printf_menos.c putnbr_printf_menos0.c putnbr_printf_menos1.c putnbr_printf_precision.c \
putnbr_printf_zeros.c putnbr_printf.c putnbr_verificar_zero.c putnbr_width_cero.c putnbr_width_prec.c putpercent_printf.c putspaces.c putstr_printf.c putunsigned_printf_aux.c \
putunsigned_printf.c putzeros.c reiniciar_.c verificar_conversion.c verificar_flags.c verificar_precision.c verificar_width.c \
			

OBJ = ${FILES:.c=.o} 

BON = ${BONUS:.c=.o}

all: $(NAME)

$(NAME): $(FILES)
	gcc $(CFLAGS) $(LFLAGS) $(FILES)
	ar rc $(NAME) $(OBJ)

#bonus:  $(FILES) $(BON)
#	gcc $(CFLAGS) $(LFLAGS) $(FILES) $(BONUS)
#	ar rc $(NAME) $(OBJ) $(BON)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re