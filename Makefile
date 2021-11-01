NAME		=	MiniRT
SRCS		=	main.c keyhooks/keyhooks.c
DIRINPUT	=	input
DIRLIBFT	=	libft
DIRMLXOGL	=	mlxogl
DIRMLXMMS	=	mlxmms
DIRUTILS	=	utils
DIRMATH		=	vec_math
DIRRAYTR	=	raytracing
LIB			=	input/input.a libft/libft.a mlxogl/libmlx.a \
				vec_math/vec_math.a raytracing/raytracing.a \
				utils/minirt_utils.a libmlx.dylib
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -lpthread
GFLAGS		=	-Wall -Wextra -Werror -g -fsanitize=address
RM			=	rm -f
AR			=	ar -rcs

all:		$(NAME)
$(NAME):	$(LIB)
			$(CC) $(CFLAGS) -Lmlxmms $(LIB) -framework OpenGL -framework AppKit $(SRCS) -o $(NAME)

$(LIB):
			$(MAKE) -C $(DIRINPUT)
			$(MAKE) -C $(DIRLIBFT)
			$(MAKE) -C $(DIRMLXOGL)
			$(MAKE) -C $(DIRMLXMMS)
			$(MAKE) -C $(DIRMATH)
			$(MAKE) -C $(DIRRAYTR)
			$(MAKE) -C $(DIRUTILS)

run:		$(NAME)
			./$(NAME) test.rt

save:		$(NAME)
			./$(NAME) test.rt --save

clean:
			$(RM) $(NAME)

fclean:		
			$(MAKE) fclean -C $(DIRINPUT)
			$(MAKE) fclean -C $(DIRLIBFT)
			$(MAKE) clean -C $(DIRMLXOGL)
			$(MAKE) clean -C $(DIRMLXMMS)
			$(MAKE) fclean -C $(DIRMATH)
			$(MAKE) fclean -C $(DIRRAYTR)
			$(MAKE) fclean -C $(DIRUTILS)
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all bonus clean fclean re %.o
