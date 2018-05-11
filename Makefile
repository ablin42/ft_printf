SRC_NAME = ft_printf.c
SRC_PATH = src
OBJ_PATH = obj
OBJ_NAME = $(SRC_NAME:.c=.o)
NAME = libftprintf.a
CC = gcc
CFLAGS = -Werror -Wall -Wextra
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)
	ranlib $(NAME)

main: $(OBJ)
	$(CC) $(CFLAGS) src/main.c $(OBJ)

$(OBJ_PATH)/%.o: $(SRC)
	@mkdir $(OBJ_PATH) 2> /dev/null
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -fv $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	rm -fv $(NAME)

re: fclean all

norme:
	norminette $(SRC)
	norminette include/*.h

.PHONY: all, clean, fclean, re
