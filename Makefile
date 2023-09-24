###############################################
CC=cc
FLAGS=-Wall -Werror -Wextra -D BUFFER_SIZE=42
###############################################

NAME=test
SRC=	get_next_line.c			\
		get_next_line_utils.c
OBJ= $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ) tests.o
	$(CC) $^ -o $(NAME)
	

%.o: %.c
	$(CC) $(FLAGS) -c $<

###############################################
t: re
	./$(NAME)

v: re
	@valgrind --leak-check=full ./$(NAME)

###############################################

clean:
	@rm -rf $(OBJ) tests.o

fclean: clean
	@rm -rf $(NAME)

re: fclean $(NAME)
