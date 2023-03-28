# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsanches <fsanches@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/27 20:49:35 by fsanches          #+#    #+#              #
#    Updated: 2023/03/27 21:01:30 by fsanches         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=minishell

SRCS = $(shell find src -name '*.c')

LIBFT = lib/libft/libft.a

OBJ	= $(SRCS:.c=.o)

$(NAME): $(OBJ)
	make bonus -s -C lib/libft
	cc -g -Wall -Wextra -Werror $(SRCS) -o $(NAME) $(LIBFT) -lreadline $(CPPFLAGS) $(LDFLAGS)

all: $(NAME)

clean:
	make clean -s -C lib/libft
	rm -f $(OBJ)

fclean: clean
	make fclean -s -C lib/libft
	rm -rf $(NAME)

re:	fclean all

.PHONY:	all clean fclean re norminette

valgrind: all
	valgrind --leak-check=full --show-reachable=yes --show-leak-kinds=all --error-limit=no --gen-suppressions=all --track-origins=yes  --log-file=lib.log ./minishell
