#PATHS
APP=./app
BIN=./bin
SRC=./src
OBJ=./obj
LIB=./lib
LIBFT=$(LIB)/libft/bin/libft.a
INCLUDE=./include
NAME = $(BIN)/libftprintf.a

#VARIABLES
SRCS=ft_printf.c ft_print_types_01.c ft_print_types_02.c ft_utils.c
OBJS=$(addprefix $(OBJ)/,$(SRCS:%.c=%.o))
HEADER=-I $(INCLUDE) -I $(LIB)/libft/include
LIBS= -L $(BIN)/libft/bin -lft
FLAGS=-Wall -Wextra -Werror
CC=cc

all: $(BIN) $(OBJ) $(LIBFT) $(NAME)

$(NAME): $(OBJS)

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) -c $(FLAGS) $(HEADER) $< -o $@ $(LIBS)
	ar -rsc $(NAME) $@

$(LIBFT):
	make -C $(LIB)/libft

$(BIN):
	mkdir $(BIN)

$(OBJ):
	mkdir $(OBJ)

clean:
	rm -rf $(OBJ)/*.o
	make clean -C $(LIB)/libft

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(LIB)/libft

re: fclean all

.PHONY: all clean fclean re

