NAME		=	minirt_utils.a
SRCS		=	minirt_error.c minirt_utils.c \
				make_bitmap.c bitmap_utils.c
OBJS		=	minirt_error.o minirt_utils.o \
				make_bitmap.o bitmap_utils.o
HEADER		=	minirt_utils.h
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
