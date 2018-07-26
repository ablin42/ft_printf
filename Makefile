SRC_NAME = ft_printf.c fill_list.c padding.c precision.c print.c \
print_format.c utils.c utils2.c extra_padding.c length_handler.c
SRC_PATH = src/
OBJ_PATH = obj/
OBJ_NAME = $(SRC_NAME:.c=.o)
NAME = libftprintf.a
LDFLAGS = -Llibft
LDLIBS = -lft
LIBFT = libft/libft.a
CC = gcc
CFLAGS = -Werror -Wall -Wextra
SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	libtool -static -o $@ $^
	ar rcs $(NAME) $(OBJ)
	ranlib $(NAME)

main: $(OBJ)
	$(CC) src/main.c $(NAME)
#	clear

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) -o $@ -c $<

clean:
	rm -fv $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	rm -fv $(NAME)

re: fclean all

norme:
	norminette $(SRC)
	norminette include/*.h

xd: re main
	clear

.PHONY: all, clean, fclean, re
