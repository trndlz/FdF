# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmervin <tmervin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/18 12:30:26 by tmervin           #+#    #+#              #
#    Updated: 2018/05/09 14:23:08 by tmervin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= fdf

SRC_PATH	:= ./src
SRC_NAME	:=	main.c		\
				init.c		\
				line.c		\
				color.c		\
				keyboard.c	\
				calc.c		\
				usage.c		\
				display.c	\
				misc.c		\
				read.c

OBJ_PATH	:= ./obj
CPPFLAGS	:= -Iincludes -I./libft/includes
HEAD_PATH	:= ./includes

CPPFLAGS	:= -Iincludes -I./libft/includes

LDFLAGS		:= -Llibft/
LDLIBS		:= -lft
MINILIBX	:= -L ./minilibx_macos/ -lmlx -framework OpenGL -framework Appkit

CC			:= gcc -Werror -Wall -Wextra
OBJ_NAME	:= $(SRC_NAME:.c=.o)
SRC			:= $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ			:= $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	make -C minilibx_macos/
	$(CC) $(LDFLAGS) $(LDLIBS) $(MINILIBX) $^ -o $@

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CPPFLAGS) -o $@ -c $<

norm:
	norminette $(HEAD_PATH)
	norminette $(SRC)

clean:
	make clean -C libft/
	make clean -C minilibx_macos/
	rm -fv $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	make fclean -C libft/
	make clean -C minilibx_macos/
	rm -fv $(NAME)

re: fclean all
