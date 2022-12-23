MAKEFLAGS += --silent
NAME= push_swap
BNAME= checker
CC = cc
SRCS= SRCS/main.c SRCS/push_swap_utils.c SRCS/stack_utils.c SRCS/moves.c SRCS/push_swap.c SRCS/stack_utils_2.c SRCS/moves2.c SRCS/utils.c
BSRCS= BSRCS/main.c SRCS/push_swap_utils.c SRCS/stack_utils.c SRCS/moves.c SRCS/push_swap.c SRCS/stack_utils_2.c SRCS/moves2.c SRCS/utils.c
LIB= ./libft/libft.a
MFILE= ./Makefile
CFLAGS = -Wall -Wextra -Werror 
RM = rm -f
OBJ = $(SRCS:.c=.o)
BOBJ = $(BSRCS:.c=.o)

all: $(NAME)

$(NAME): $(MFILE) $(SRCS) $(OBJ)
	make -C libft
	$(CC) $(CFLAGS) -I ./ $(OBJ) $(LIB) -o $@
	echo "push_swap is created"

%.o: %.c
		$(CC) $(CFLAGS) -I. -o $@ -c $?

bonus: $(MFILE) $(BSRCS) $(BOBJ)
	make -C libft
	$(CC) $(CFLAGS) -I ./ $(BOBJ) $(LIB) -o $(BNAME)
	echo "checker is created"

clean:
		make clean -C libft
		$(RM) $(OBJ) $(BOBJ)

fclean: clean
		make fclean -C libft
		$(RM) $(NAME) $(BNAME)
		echo "all is deleted"

re: fclean all