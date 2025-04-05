##
## EPITECH PROJECT, 2024
## B-MUL-100-MPL-1-1-myhunter-teddy.bertrand
## File description:
## Makefile
##

NAME = my_radar

SRC = $(shell find -name "*.c")

FLAGS = -lcsfml-window -lcsfml-system -lcsfml-graphics -lcsfml-audio

CFLAGS = -lm -g3

WFLAGS = -W -Werror -Wextra -Wall

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS) $(FLAGS) $(WFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
