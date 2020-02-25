# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccardozo <ccardozo@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/24 12:08:56 by ccardozo          #+#    #+#              #
#    Updated: 2020/02/24 15:12:16 by ccardozo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PF = ft_printf.c	p_aux.c	bag.c	hexnum.c	pointmem.c    \
		 spaces.c	unsgint.c	utils.c 
SRC_LFT = *.c
OBJET_PF =  $(SRC_PF:.c=.o)
OBJET_LFT = $(SRC_LFT:.c=.o)
LIBFT_PATH =  libft
bag = -Wall -Werror -Wextra
LIB = $(addprefix $(LIBFT_PATH)/, $(OBJET_LFT))
GCC = gcc
AR = ar
ARbag = rc
MAKE = make
.PHONY: clean fclean all re
all: $(NAME)
$(NAME): $(OBJET_PF) $(SRC_PF)
	@$(MAKE) -C $(LIBFT_PATH)
	@echo Compiling $(NAME)
	@$(GCC) $(bag) -c $(SRC_PF)
	@$(AR) $(ARbag) $(NAME) $(OBJET_PF) $(LIB)
	@ranlib $(NAME)
	@echo ======[Done]=====
clean:
		@$(MAKE) -C $(LIBFT_PATH) clean
		@echo Clean objects $(NAME)
		@rm -rf $(OBJET_PF) *.o
fclean: clean
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@echo Clean $(NAME)
	@rm -rf $(NAME)
	@echo ======[Clean]======
re: fclean all
