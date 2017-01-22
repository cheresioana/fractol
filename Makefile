# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfazakas <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/18 10:05:52 by jfazakas          #+#    #+#              #
#    Updated: 2017/01/22 21:55:53 by icheres          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
SRC = *.c includes/libft/*.c aux/util1.c aux/mlx_res/*.c  
OBJ = *.o
INC = includes/
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc -o $(NAME) $(SRC) -L ./includes -lmlx -framework OpenGL -framework AppKit
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
