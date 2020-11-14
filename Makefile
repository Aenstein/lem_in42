CC = gcc
NAME = lem-in
HEADER = includes
LIB = ./libft
LIB_H = $(LIB)/includes/
LIB_SRC = $(LIB)/*.c
LIB_SRC_PRINTF = $(LIB)/srcs_for_printf/*.c

FLAGS = -Wall -Wextra -Werror -I $(HEADER) -I $(LIB_H)
SOURCES =	lemin.c parse.c hash.c room.c check.c link.c \
			edge.c way1.c bellman_ford.c bhandari.c printer.c \
			counter.c validation.c solution.c print.c way2.c

DIR_S = src
DIR_O = obj
SRC = $(addprefix $(DIR_S)/,$(SOURCES))
OBJ = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJ) $(HEADER) Makefile $(LIB_H) $(LIB_SRC) $(LIB_SRC_PRINTF)
	@make -C $(LIB)
	@gcc $(FLAGS) -o $(NAME) $(OBJ) -L./$(LIB) -lft
	@echo "$(NAME) IS READY FOR NAGIB"

$(DIR_O)/%.o: $(DIR_S)/%.c
	@mkdir -p $(DIR_O)
	@$(CC) $(FLAGS) -I $(HEADER) -o $@ -c $< -g

clean:
	make clean -C libft
	@rm -f $(OBJ)
	@rm -rf $(DIR_O)

fclean: clean
	make fclean -C libft
	@rm -f $(NAME)

re: fclean all
