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

all: $(NAME) client

$(NAME): libft.a
	gcc -o server.out server.c utils.c -l ft -L libft -I libft

client: libft.a
	gcc -o client.out client.c utils.c -l ft -L libft -I libft

clean:
	rm libft/*.o

libft.a:
	make -C libft

fclean: clean
	rm libft/*.a *.out

re: fclean all client
