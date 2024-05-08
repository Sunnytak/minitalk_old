# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stak <stak@student.hive.fi>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/06 13:54:51 by stak              #+#    #+#              #
#    Updated: 2024/05/08 14:19:10 by stak             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# SOURCES = server.c client.c
# OBJECTS = $(SOURCES:.c=.o)

# CC = gcc
# CFLAGS = -Wall -Wextra -Werror

# all: server client

# bonus: server client

# server: server.o libft
# 	$(CC) -o $@ $< -Llibft -lft

# client: client.o libft
# 	$(CC) -o $@ $< -Llibft -lft

# %.o: %.c
# 	$(CC) -c $(CFLAGS) $?

# libft:
# 	make -C libft

# clean:
# 	rm -f $(OBJECTS)
# 	make -C libft clean
	
# fclean: clean
# 	rm -f server client libft/libft.a

# re: fclean all

# .PHONY: all bonus libft clean fclean re

CLIENT = client
SERVER = server
LIBFT = libft

SOURCE_CLIENT = client.c
				
SOURCE_SERVER = server.c

OBJECTS_C = $(SOURCE_CLIENT:.c=.o)
OBJECTS_S = $(SOURCE_SERVER:.c=.o)

all: $(CLIENT) $(SERVER)

$(CLIENT): $(OBJECTS_C) $(LIBFT)
	make -C $(LIBFT)
	$(CC) $(CFLAGS) -o $(CLIENT) $(OBJECTS_C) -L$(LIBFT) -lft

$(SERVER): $(OBJECTS_S) $(LIBFT)
	make -C $(LIBFT)
	$(CC) $(CFLAGS) -o $(SERVER) $(OBJECTS_S) -L$(LIBFT) -lft 

CC: HCC

CFLAGS += -Wall -Wextra -Werror

	
clean: 
	make clean -C $(LIBFT)
	rm -f $(OBJECTS_C) $(OBJECTS_S)

fclean: clean
	make fclean -C $(LIBFT)
	rm -f $(CLIENT) $(SERVER)

re: fclean all

.PHONY: all bonus clean fclean re