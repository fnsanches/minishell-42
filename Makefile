NAME			= minishell
LIBFT			= libft.a

#compilation
CC 				= cc
# CF 				= -g -Wall -Wextra -Werror
CFI 			= -I $(INCLUDE)
CREADLINE		= -lreadline

LIBFT_PATH 		= ./libft/
SRC_PATH 		= ./src/
OBJ_PATH		= ./objs_minishell/
INCLUDE 		= ./inc/

SRC				= minishell.c utils.c lexer_utils.c lexer_utils2.c \
					expander_utils.c prompt.c \
					parser.c parser_utils.c executor.c

				

VPATH 			:= $(SRC_PATH)\

OBJ				= $(addprefix $(OBJ_PATH), $(notdir $(SRC:.c=.o)))

RM 				= rm -rf

$(OBJ_PATH)%.o: %.c
				mkdir -p $(OBJ_PATH)
				$(CC) $(CF) $(CFI) -c $< -o $@

$(NAME):		$(OBJ)
				make -C $(LIBFT_PATH)
				$(CC) -g $(CF) -I $(INCLUDE) -o $(NAME) $(OBJ) $(CREADLINE) -L $(LIBFT_PATH) -lft


all:			$(NAME)

re:				fclean all

clean:
				$(RM) $(OBJ) $(OBJDIR)

fclean:			clean
				$(RM) $(NAME)

.PHONY:			all clean fclean re