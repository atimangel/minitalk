# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/16 13:44:48 by snpark            #+#    #+#              #
#    Updated: 2021/06/18 16:46:11 by snpark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server

all: $(NAME) client

$(NAME):
	make -C libft
	gcc -o server.out server.c utils.c -l ft -L libft -I libft

client:
	make -C libft
	gcc -o client.out client.c utils.c -l ft -L libft -I libft

clean:
	rm libft/*.o

fclean: clean
	rm libft/*.a
	rm *.out

re: fclean all client
