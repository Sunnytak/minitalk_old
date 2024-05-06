# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stak <stak@student.hive.fi>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/06 13:54:51 by stak              #+#    #+#              #
#    Updated: 2024/05/06 14:56:59 by stak             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
LIBFT = ./libft
PRINTF = ./ft_printf

MY_SOURCE = client.c \
			server.c

OBJECTS = $(MY_SOURCE:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT)
	make -C $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) -L$(LIBFT) -lft 

CC: HCC

CFLAGS += -Wall -Wextra -Werror

clean: 
	make clean -C $(LIBFT)
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re