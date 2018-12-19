# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ffahey <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/17 13:11:37 by ffahey            #+#    #+#              #
#    Updated: 2018/12/19 15:56:12 by ffahey           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
vpath %.c srcs
vpath %.o bin
vpath %.h includes

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SRC_PATH = srcs
HEAD_PATH = includes
BIN_PATH = bin

SRC = ft_printf.c ft_read_format.c ft_create_format.c

OBJ = $(patsubst %.c,bin/%.o,$(SRC))

.PHONY: all clean fclean re

all: $(BIN_PATH) $(NAME)

$(BIN_PATH):
	@mkdir bin

$(NAME): $(OBJ)
	ar rc $@ $^
	ranlib $@

$(BIN_PATH)/%.o: $(SRC_PATH)/%.c
	gcc $(CFLAGS) -c $^ -o $@ -I$(HEAD_PATH)

clean:
	@rm -rf bin

fclean: clean
	@rm -f $(NAME)

re: fclean all
