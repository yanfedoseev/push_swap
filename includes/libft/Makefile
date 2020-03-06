# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgeorgin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/15 15:18:42 by lgeorgin          #+#    #+#              #
#    Updated: 2020/02/15 15:18:51 by lgeorgin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

PRINTF_DIR 	= ./printf
LIB_DIR 			= ./lib

PRINTF_FILES =	ft_printf.c \
			parameter_parser.c \
			parameter_parser_subroutines.c \
			check_options.c \
			try_dollar.c \
			utf8.c \
			get_unformatted_string_switch.c \
			get_unformatted_string_cs.c \
			get_unformatted_string_pdioux_utf.c \
			get_unformatted_string_double_switch.c \
			get_unformatted_string_f.c \
			get_unformatted_string_e.c \
			get_unformatted_string_g.c \
			dbl_exceptions_processing.c \
			dbl_subroutines_1.c \
			dbl_subroutines_2.c \
			dbl_itoa_base.c \
			get_formatted_string.c \
			apply_default_type_options.c \
			apply_width.c \
			apply_length.c \
			apply_flags.c \
			apply_precision.c \
			join_strings.c \
			ft_itoa_base.c \
			subroutines_length_calc.c \
			long_calc_math.c \
			display.c \
			undefined_behaviour.c \
			cleaner.c


LIB_FILES = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
				ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c \
				ft_strncpy.c ft_strcat.c ft_strlcat.c ft_strchr.c ft_strrchr.c \
				ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c \
				ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
				ft_toupper.c ft_tolower.c ft_memalloc.c ft_memdel.c ft_strnew.c \
				ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c \
				ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c \
				ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c ft_putstr.c \
				ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c \
				ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c \
				ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_strncat.c \
				ft_strtrimi.c ft_strclean.c ft_strndup.c ft_lstfree.c \
				ft_count_words.c ft_skip.c ft_word.c ft_arrfree.c ft_nmbrlen.c \
				get_next_line.c

SRCS = $(addprefix $(PRINTF_DIR)/,$(PRINTF_FILES))
SRCS += $(addprefix $(LIB_DIR)/,$(LIB_FILES))
OBJS = $(PRINTF_FILES:.c=.o)
OBJS += $(LIB_FILES:.c=.o)

CC = gcc -g
CFLAGS = -Wall -Wextra -Werror
LFLAGS = -I ./libft/ -I ./srcs/

%.o:$(PRINTF_DIR)/%.c
	@$(CC) $(CFLAGS) $(LFLAGS) -o $@ -c $<
%.o:$(LIB_DIR)/%.c
	@$(CC) $(CFLAGS) $(LFLAGS) -o $@ -c $<

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

clean:
	@make clean -C $(LIB_DIR)
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C $(LIB_DIR)

re: fclean $(NAME)
