NAME		=	raytracing.a
SRCS		=	intersect.c intersect_cylinder.c \
				light.c raytracing.c cast_ray.c
OBJS		=	intersect.o intersect_cylinder.o \
				light.o raytracing.o cast_ray.o
HEADER		=	raytracing.h
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
