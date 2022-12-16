MAKEFLAGS += --silent
NAME= push_swap
CC = cc
SRCS= main.c push_swap_utils.c stack_utils.c moves.c push_swap.c
#BSRCS=
LIB= ./libft/libft.a
CFLAGS = -Wall -Wextra -Werror 
RM = rm -f
OBJ = $(SRCS:.c=.o)
# BOBJ = $(BSRCS:.c=.o)

all: $(NAME)

$(NAME): $(SRCS) $(OBJ)
	make -C libft
	$(CC) $(CFLAGS) -I ./ $(OBJ) $(LIB) -o $@
	echo "push_swap is created"

%.o: %.c
		$(CC) $(CFLAGS) -I. -o $@ -c $?

# bonus: $(BOBJ)
# 	make -C libft
# 	$(CC) $(CFLAGS) -I . $(MLX_FLAGS) $(BOBJ) $(LIB) -o $(NAME)
# 	echo "so_long bonus is created"

clean:
		make clean -C libft
		$(RM) $(OBJ) $(BOBJ)

fclean: clean
		make fclean -C libft
		$(RM) $(NAME)
		echo "push_swap is deleted"

re: fclean all