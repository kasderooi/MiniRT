NAME		=	vec_math.a
SRCS		=	math_utils.c matrix_math_1.c\
				color_math_1.c color_math_2.c\
				vector_math_1.c vector_math_2.c
OBJS		=	math_utils.o matrix_math_1.o\
				color_math_1.o color_math_2.o\
				vector_math_1.o vector_math_2.o
HEADER		=	math.h
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -c
GFLAGS		=	-Wall -Wextra -Werror -c -I. -g -fsanitize=address
RM			=	rm -f
AR			=	ar -rcs

all:		$(NAME)
$(NAME):	$(OBJS)
			$(AR) $(NAME) $(OBJS)

%.o:	%.c $(HEADER)
			$(CC) $(CFLAGS) -o $@ $<

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all bonus clean fclean re %.o
