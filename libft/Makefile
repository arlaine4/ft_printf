# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arlaine <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/03 16:03:21 by arlaine           #+#    #+#              #
#    Updated: 2019/03/03 16:14:38 by arlaine          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = 	ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c\
		ft_isdigit.c ft_isprint.c ft_itoa.c ft_memalloc.c ft_memccpy.c\
		ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c\
		ft_memset.c ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c\
		ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_strcat.c\
		ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c\
		ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c\
		ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c\
		ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strrchr.c\
		ft_strsplit.c ft_strstr.c ft_strnstr.c ft_strsub.c ft_strtrim.c\
		ft_tolower.c ft_toupper.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c\
		ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_sqrt.c ft_lstsize.c\
		ft_atoll.c ft_isprime.c ft_next_prime.c get_next_line.c ft_fdline.c\
		ft_cptchar.c ft_putnbrl.c ft_power.c ft_putnbrll.c ft_itoll.c ft_to_lower.c\

HEADER = libft.h
OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -Werror -Wextra
all: $(NAME)

$(NAME): $(OBJ)
	@ar -r $(NAME) *.o
	@echo ./$(NAME)
	@ranlib $(NAME)

$(OBJDIR)%.o: %.c
	@gcc -o $@ -c $< $(CFLAGS)
	@echo "\033[0;32m [COMPILE] \033[0m" $<

clean:
	rm -f *.o

fclean:	clean
	rm -f $(NAME)

re: fclean all
