NAME_PS		=	push_swap
NAME_CH		=	checker

CFLAGS		=	-Wall -Wextra -Werror

SRC_COMMON	=	validation.c commands.c my.c my_exit.c display.c

SRC_PS		=	$(SRC_COMMON) \
				push_swap.c \
				sort_3_and_5_element.c \
				global_sort.c finding_place.c

SRC_CH		=	$(SRC_COMMON) \
				checker.c

OBJ_DIR		=	obj

OBJ_PS		=	$(addprefix $(OBJ_DIR)/,$(SRC_PS:.c=.o))

OBJ_CH		=	$(addprefix $(OBJ_DIR)/,$(SRC_CH:.c=.o))

INC			=	-I./includes
LIBFT_INC	=	-I./includes/libft

LIB_BINARY	=	-L./includes/libft -lft
LIBFT		=	./includes/libft/libft.a

all: $(LIBFT)	./includes/libft/libft.a $(NAME_PS) $(NAME_CH)

$(LIBFT):
	make -C ./includes/libft

$(OBJ_DIR):
	mkdir $@

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	gcc -g $(CFLAGS) $(INC) $(LIBFT_INC) -c $< -o $@

$(NAME_PS): $(OBJ_PS) $(LIBFT) ./includes/push_swap.h
	gcc -g $(OBJ_PS) $(LIB_BINARY) -o $@

$(NAME_CH): $(OBJ_CH) $(LIBFT) ./includes/push_swap.h
	gcc -g $(OBJ_CH) $(LIB_BINARY) -o $@

clean:
	rm -rf $(OBJ_DIR)
	make -C ./includes/libft clean

fclean: clean
	/bin/rm -f $(NAME_PS)
	/bin/rm -f $(NAME_CH)
	make -C ./includes/libft fclean

re: fclean all
