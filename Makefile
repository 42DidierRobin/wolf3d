# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdidier <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/27 18:34:25 by rdidier           #+#    #+#              #
#    Updated: 2016/03/29 18:10:28 by rdidier          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	wolf3d

SRC		=	sources/main.c							\
			sources/image.c							\
			sources/launch.c						\
			sources/read.c							\
			sources/struct.c						\
			sources/algo_temp.c						\
			

MAP		=	map/map0

OBJ		=	$(patsubst src/%.c,./%.o,$(SRC))

FLAG	=	-Wall -Werror -Wextra -framework OpenGL -framework AppKit

.SILENT:

$(NAME): $(OBJ)
	make -C libft/
	gcc $(FLAG) $(OBJ)  -L/usr/local/lib -lmlx -L libft/ -lft -o $(NAME)
	printf '\033[4m'
	printf '\033[32m[ ✔ ] %s\n\033[0m' "$(NAME) is done !"
./%.o: src/%.c
	gcc $(FLAG) -c $< -o $@
	printf '\033[0m[ ✔ ] %s\n\033[0m' "$<"

clean:
	make -C libft/ clean
	/bin/rm -rf *.o
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Clean"

fclean: clean
	make -C libft/ fclean
	/bin/rm -f $(NAME)
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Fclean"

javel:
	clear

boom : javel fclean $(NAME) clean
	./$(NAME) $(MAP)

re: fclean all

all: $(NAME)

.PHONY: clean fclean re all
