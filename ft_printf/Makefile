# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stak <stak@student.hive.fi>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/13 16:19:16 by stak              #+#    #+#              #
#    Updated: 2023/12/13 17:54:47 by stak             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

MY_SOURCE = ft_printf.c \
			ft_hexconvert.c \
			ft_printchar.c \
			ft_printnbr.c \
			ft_printstr.c \
			ft_print_unsigned.c \
			ft_print_ptr.c \

OBJECTS = $(MY_SOURCE:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rc $(NAME) $(OBJECTS)

CC: HCC

CFLAGS += -Wall -Wextra -Werror

clean: 
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re