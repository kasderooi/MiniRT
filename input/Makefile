NAME		=	input.a
LIBFTSRCS	=	get_next_line_utils.c get_next_line.c read_file.c \
				makedata_basic.c makedata_environment.c makedata_shape.c \
				translate_camera.c input_utils.c error.c
LIBFTOBJS	=	get_next_line_utils.o get_next_line.o read_file.o \
				makedata_basic.o makedata_environment.o makedata_shape.o \
				translate_camera.o input_utils.o error.o
HEADER		=	input.h
CC			=	gcc
CFLAGS		=	-c
GFLAGS		=	-Wall -Wextra -Werror -c -I. -g -fsanitize=address
RM			=	rm -f
AR			=	ar -rcs

all:		$(NAME)
$(NAME):	$(LIBFTOBJS)
			$(AR) $(NAME) $(LIBFTOBJS)

%.o:	%.c $(HEADER)
			$(CC) $(CFLAGS) -D BUFFER_SIZE=128 -o $@ $<

clean:
			$(RM) $(LIBFTOBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all bonus clean fclean re %.o
