NAME		=	libft.a
LIBFTSRCS	=	ft_atoi.c ft_calloc.c ft_itoa.c ft_itoa_base.c ft_memmove.c \
				ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
				ft_putstr_fd.c ft_putfloat_fd.c ft_strdup.c ft_strjoin.c \
				ft_strlcat.c ft_strlen.c ft_strndup.c ft_substr.c ft_bzero.c \
				ft_isdigit.c ft_nbrlen.c ft_nbrlen_base.c ft_atof.c\
				ft_strncmp.c ft_isspace.c ft_splitspace.c ft_strnlen.c \
				ft_strchr.c ft_lists.c ft_strnstr.c ft_strstr.c ft_split.c \
				ft_freesplit.c ft_putdouble_fd.c ft_memcpy.c
LIBFTOBJS	=	ft_atoi.o ft_calloc.o ft_itoa.o ft_itoa_base.o ft_memmove.o \
				ft_memset.o ft_putchar_fd.o ft_putendl_fd.o ft_putnbr_fd.o \
				ft_putstr_fd.o ft_putfloat_fd.o ft_strdup.o ft_strjoin.o \
				ft_strlcat.o ft_strlen.o ft_strndup.o ft_substr.o ft_bzero.o \
				ft_isdigit.o ft_nbrlen.o ft_nbrlen_base.o ft_atof.o\
				ft_strncmp.o ft_isspace.o ft_splitspace.o ft_strnlen.o \
				ft_strchr.o ft_lists.o ft_strnstr.o ft_strstr.o ft_split.o \
				ft_freesplit.o ft_putdouble_fd.o ft_memcpy.o
HEADER		=	libft.h
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -c
GFLAGS		=	-Wall -Wextra -Werror -c -I. -g -fsanitize=address
RM			=	rm -f
AR			=	ar -rcs

all:		$(NAME)
$(NAME):	$(LIBFTOBJS)
			$(AR) $(NAME) $(LIBFTOBJS)

%.o:	%.c $(HEADER)
			$(CC) $(CFLAGS) -o $@ $<
clean:
			$(RM) $(LIBFTOBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all bonus clean fclean re %.o
