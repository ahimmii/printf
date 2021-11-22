CC := gcc
W := -c -Wall -Werror -Wextra
CFILES := ft_printf.c ft_printf_utils.c
OFILES := ${CFILES:.c=.o}
NAME := libftprintf.a
INC := ft_printf.h

${NAME} : ${OFILES} ${INC}
	@${CC} ${W} ${CFILES}
	@ar -rc ${NAME} ${OFILES}
clean :
	@rm -f  ${OFILES}
fclean : clean
	@rm -f ${NAME}
re : fclean all
all : ${NAME}
