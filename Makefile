# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/16 13:44:48 by snpark            #+#    #+#              #
#    Updated: 2021/06/16 13:51:00 by snpark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all: $(NAME)

$(NAME): server client

client: libft
	gcc -o client client.c utils.c -l ft -L libft -I libft

server: libft
	gcc -o server server.c utils.c -l ft -L libft -I libft

libft:
	make -C libft

clean:

fclean:

re: fclean all
