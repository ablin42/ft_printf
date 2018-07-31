SRC_NAME = conv_test.c length_mod_test.c mix_test.c preci_test.c width_test.c \
ub_test.c
OBJ_PATH = obj/
OBJ_NAME = $(SRC_NAME:.c=.o)
NAME = run_tests
CC = gcc
CFLAGS = -w
SRC = $(SRC_NAME)
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	cd .. && make
	$(CC) main.c -o $(NAME) $(OBJ) ../libftprintf.a

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -fv $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	rm -fv $(NAME)

re: fclean all

xd: re
	clear

.PHONY: all, clean, fclean, re