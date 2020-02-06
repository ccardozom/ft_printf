# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/06 13:15:54 by ccardozo          #+#    #+#              #
#    Updated: 2020/02/06 13:15:54 by ccardozo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#--------------------Recursos---------------------------#

SRCS =	destructor.c initialize.c processline.c ft_printf.c \
		reinitialize.c check_flags.c check_width.c check_precisition.c \
		check_conversion.c executer.c putspaces.c ft_putnstr.c putstr_printf.c \
		ft_isdigit.c ft_putchar.c ft_strchr.c ft_strldup.c ft_strlen.c ft_substr.c \
		ft_strdup.c ft_strcpy.c putchar_printf.c putpercent_printf.c putzeros.c \
		putnbr_printf.c ft_nbrlen.c putnbr_printf_aux.c putnbr_printf_aux2.c \
		putunsigned_printf.c putunsigned_printf_aux.c puthex_printf.c puthex_printf_aux.c \
		putmemory_printf.c putmemory_printf_aux.c \

NAME = libftprintf.a

all: ${NAME}

COMMAND = ar rc ${NAME} ${OBJS}

COMMAND2 = ranlib ${NAME}

GCC = gcc -Wall -Werror -Wextra -g

CREATEMKDIR = @mkdir -p objs

OBJS = ${SRCS:.c=.o}

RM = rm -rf


.c.o:
			${CREATEMKDIR}
			@${GCC} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS} ${INCLUDE}
			@${COMMAND}
			@${COMMAND2}

re:			fclean all

clean:
			@${RM} ${OBJS}

fclean:
			@${RM} ${NAME} ${CREATEMKDIR}
