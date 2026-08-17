NAME = push_swap.a

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

FTPRINTF_DIR = printf
FTPRINTF = $(FTPRINTF_DIR)/libftprintf.a

SRCS = push.c rotate.c rev_rotate.c\
swap.c stack_utils.c disorder.c\
parser.c parser_utils.c

OBJS = ${SRCS:.c=.o}

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

INCLUDES = -Iincludes -I$(LIBFT_DIR) -I$(FTPRINTF_DIR)

all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(FTPRINTF):
	make -C $(FTPRINTF_DIR)
	
$(NAME) : $(OBJS) $(LIBFT) $(FTPRINTF)
	ar rcs $(NAME) $(OBJS)

.c.o:	
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $(<:.c=.o)

clean:
	$(RM) $(OBJS)
	make -C $(LIBFT_DIR) clean
	make -C $(FTPRINTF_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(FTPRINTF_DIR)	fclean

re: fclean all

.PHONY: all fclean clean re