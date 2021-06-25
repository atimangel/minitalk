# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/16 13:44:48 by snpark            #+#    #+#              #
#    Updated: 2021/06/22 11:56:56 by senoi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server
LEAK = -fsanitize=address
CFLAG = -Wall -Werror -Wextra

all: $(NAME) client

$(NAME): libft.a
	gcc -o server $(LEAK) $(CFLAG) server.c utils.c -l ft -L libft -I libft

client: libft.a
	gcc -o client $(LEAK) $(CFLAG) client.c utils.c -l ft -L libft -I libft

bonus : libft.a
	gcc -o server_bonus $(LEAK) $(CFLAG) server_bonus.c utils_bonus.c -l ft -L libft -I libft
	gcc -o client_bonus $(LEAK) $(CFLAG) client_bonus.c utils_bonus.c -l ft -L libft -I libft

clean:
	rm libft/*.o

libft.a:
	make -C libft

fclean:
	rm libft/*.o libft/*.a client server client_bonus server_bonus

re: fclean all client
