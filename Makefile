SRC		=	get_next_line.c			\
			get_next_line_utils.c

OBJS	=	$(SRC:.c=.o)

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror -D BUFFER_SIZE=10000000

NAME	=	get_next_line.a

all:		$(NAME)

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

clean:	
			rm -f $(OBJS)


fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re