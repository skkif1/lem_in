
CC = gcc -Wall -Wextra -Werror


NAME = lem-in

FT_LS_SRC = main.c parse.c util.c find_path.c ant.c graph.c paralel_path.c

OBJECTS = $(subst .c,.o,$(FT_LS_SRC))

$(NAME): $(OBJECTS)
	@make -C libft/
	gcc $(OBJECTS) -o $(NAME) libft/libftprintf.a


all: $(NAME)

clean: 
	@make -C libft/ clean
	rm -rf $(OBJECTS)

fclean: clean
	@make -C libft/ fclean
	rm -rf $(NAME) $(OBJECTS)

re: fclean all