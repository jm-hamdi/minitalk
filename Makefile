# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jm-hamdi <jm-hamdi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/08 20:37:40 by jm-hamdi          #+#    #+#              #
#    Updated: 2022/06/08 20:37:41 by jm-hamdi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra
CLIENT = client
SERVER = server
CLIENT_BONUS = client_bonus
SERVER_BONUS = server_bonus

all: $(CLIENT) $(SERVER)

$(CLIENT) : client.c 
		$(CC) $(CFLAGS) client.c utils.c -o client
$(SERVER) : server.c
		$(CC) $(CFLAGS) server.c utils.c -o server

bonus: $(CLIENT_BONUS) $(SERVER_BONUS)

$(CLIENT_BONUS) : client_bonus.c
		$(CC) $(CFLAGS) client_bonus.c utils.c -o client_bonus
$(SERVER_BONUS) : server_bonus.c
		$(CC) $(CFLAGS) server_bonus.c utils.c -o server_bonus
fclean:
	rm -rf $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)

re: fclean all bonus
