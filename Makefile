# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arlaine <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/03 16:18:04 by arlaine           #+#    #+#              #
#    Updated: 2019/03/03 16:18:08 by arlaine          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

HEADER = includes

SRCS = srcs/basic_print.c srcs/ft_aux.c srcs/ft_lltoa.c srcs/ft_print.c \
	   srcs/ft_printf.c srcs/ft_putfloat.c srcs/parsing.c srcs/conv_d.c

OBJS = $(SRCS:.c=.o)

FLAGS = -c -Wall -Wextra -Werror

all: $(NAME) 

$(NAME):
		make -C libft
		@gcc $(FLAGS) $(SRCS) -I $(HEADER)
		@ar rc $(NAME) *.o libft/*.o

clean:
		@rm -rf *.o
		@make clean -C libft

fclean: clean
		@rm -rf $(NAME)
		@make fclean -C libft

re: fclean all
