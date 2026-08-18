NAME = libftprintf.a

SRCS = functions.c ft_printf.c \
printf_float.c

OBJS = ${SRCS :.c =.o}

CC = gcc

RM = rm -f

CFLAGS = -Wall - Werror -Wextra

.c.o: 
	${CC} ${CFLAGS} -c $ <-o ${ < :.c =.o}

${NAME} : ${OBJS} 
	ar rcs ${NAME} ${OBJS}

all : ${NAME}

clean : 
	${RM} ${OBJS}

fclean : clean 
	${RM} ${NAME}

re : fclean all

.PHONY: all fclean clean re