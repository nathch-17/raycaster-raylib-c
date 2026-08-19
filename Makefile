CC = gcc 
CFLAGS = -Wall -Wextra -Werror -I include -lraylib -lm
NAME = jeu_test
SRC = src/jeu.c \

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 
