MAKEFLAGS += --silent

NAME = push_swap

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

FTPRINTF_DIR = printf
FTPRINTF = $(FTPRINTF_DIR)/libftprintf.a

SRCS = push.c rotate.c rev_rotate.c\
swap.c stack_utils.c disorder.c\
parser.c parser_utils.c chunk_sort.c\
chunk_sort_utils.c quick_sort.c\
quick_sort_utils.c simple_sort.c\
parser_split.c main.c benchmode.c

OBJS = ${SRCS:.c=.o}

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

INCLUDES = -Iincludes -I$(LIBFT_DIR) -I$(FTPRINTF_DIR)

#colors
RESET = \033[0m
GREEN = \033[32m

all: $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(FTPRINTF):
	@make -C $(FTPRINTF_DIR)

$(NAME) : $(OBJS) $(LIBFT) $(FTPRINTF)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(FTPRINTF) -o $(NAME)
	@echo "$(GREEN) done $(RESET)"

.c.o:	
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $(<:.c=.o)

clean:
	@$(RM) $(OBJS)
	@make -C $(LIBFT_DIR) clean
	@make -C $(FTPRINTF_DIR) clean
	@echo "$(GREEN) done $(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@make -C $(FTPRINTF_DIR) fclean
	@echo "$(GREEN) done $(RESET)"

re: fclean all

.PHONY: all fclean clean re