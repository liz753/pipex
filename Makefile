
NAME 	= pipex

CC		= gcc

CFLAGS	=	-Wall -Werror -Wextra -g 

RM		= rm -f 

LIB		= libs//libft/libft.a

SRC = pipex.c 

OBJS = ${SRC:%.c=%.o}

all		: $(NAME)

$(NAME)	: $(OBJS)
	$(CC) $(OBJS) $(LIB) $(CFLAGS) -o $(NAME)

clean	: 
	$(RM) $(OBJS)

fclean	: clean
	$(RM) $(NAME)


re		: fclean all