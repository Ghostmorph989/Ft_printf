# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malaoui <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/06 17:35:50 by malaoui           #+#    #+#              #
#    Updated: 2019/11/07 14:11:46 by malaoui          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c\
	ft_base.c\
	ft_padding.c\
	ft_precision.c

LIB = libft.a

FLAGS = -Wall -Werror -Wextra -c

GC = gcc

all: $(NAME)

$(NAME):
	$(GC) $(FLAGS) $(SRC)
	ar rc $(NAME) $(SRC:.c=.o)
	ranlib $(NAME)

clean:
	rm -f $(SRC:.c=.o)

fclean: clean
	rm -f $(NAME)

re: fclean all
