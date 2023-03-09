# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfrank <lfrank@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/01 11:07:08 by lfrank            #+#    #+#              #
#    Updated: 2023/02/01 13:54:28 by lfrank           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= pipex

NAME_BONUS	= pipex_bonus

CC			= gcc

CFLAGS		=	-Wall -Werror -Wextra -g 

RM			= rm -f 

LIB			= ./libs/libft/libft.a

MAKE_LIBFT	= cd ./libs/libft && make

CLEAR_LIBFT	= cd ./libs/libft && make fclean

SRC			= ./src/main.c ./src/pipex.c ./src/ft_error_message.c \
				./src/ft_get_cmd.c

OBJS = ${SRC:%.c=%.o}

all		: $(NAME)

$(NAME)	: $(OBJS)
	$(MAKE_LIBFT)
	$(CC) $(OBJS) $(LIB) $(CFLAGS) -o $(NAME)

clean	: 
	@$(MAKE)  -C ./libs/libft clean
	$(RM) $(OBJS)

fclean	: clean
	@$(MAKE) -C ./libs/libft fclean
	$(RM) $(NAME)

rmfile	: clean
	$(RM) outfile
	$(RM) infile
	$(RM) output

re		: fclean all