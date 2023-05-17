##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile
##

NAME = mysh

SRC = ./src/main.c \
	  ./src/wait_command.c \
	  ./src/execute_command.c \
	  ./src/all_command.c \
	  ./src/command_cd.c \
	  ./src/event_env.c \
	  ./src/my_strnncat.c \
	  ./src/my_str_to_word_array.c \
	  ./src/copy_array.c \
	  ./src/command_setenv.c \
	  ./src/child_process.c \
	  ./src/find_command_path.c \

OBJ = $(SRC:.c=.o)

CFLAGS = -I ./include/ -W -Wall -Wextra -g3

LIB = -L ./lib/ -lmy

%.o: %.c
	@gcc -c $< -o $@ $(CFLAGS)

NOPRINT = --no-print-directory

$(NAME): $(OBJ)
	@make -C ./lib/my/ $(NOPRINT)
	@gcc $(OBJ) -o $(NAME) $(CFLAGS) $(LIB)

all: $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C ./lib/my/ $(NOPRINT)
	@rm -f lib/libmy.a

re: fclean all

.PHONY : all clean fclean re
