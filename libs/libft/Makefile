# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfrank <lfrank@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/26 12:11:55 by lfrank            #+#    #+#              #
#    Updated: 2023/02/01 11:18:18 by lfrank           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC	=	ft_atoi.c		\
		ft_bzero.c		\
		ft_calloc.c		\
		ft_isalnum.c	\
		ft_isalpha.c	\
		ft_isascii.c	\
		ft_isdigit.c	\
		ft_isprint.c	\
		ft_itoa.c	    \
		ft_memchr.c		\
		ft_memcmp.c		\
		ft_memcpy.c		\
		ft_memmove.c	\
		ft_memset.c		\
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c	\
		ft_putstr_fd.c	\
		ft_split.c		\
		ft_strchr.c		\
		ft_strdup.c		\
		ft_striteri.c   \
		ft_strjoin.c	\
		ft_strlcat.c 	\
		ft_strlcpy.c	\
		ft_strlen.c 	\
		ft_strmapi.c    \
		ft_strncmp.c	\
		ft_strnstr.c	\
		ft_strrchr.c	\
		ft_strtrim.c	\
		ft_substr.c		\
		ft_tolower.c	\
		ft_toupper.c	\
		get_next_line_utils.c \
		get_next_line.c \

SRC_BONUS = ft_lstnew.c			\
			 ft_lstadd_front.c	\
			 ft_lstsize.c		\
			 ft_lstlast.c    	\
			 ft_lstadd_back.c   \
			 ft_lstdelone.c		\
			 ft_lstclear.c		\
			 ft_lstiter.c		\
			 ft_lstmap.c		\

OBJS = $(SRC:.c=.o)

OBJS_BONUS = $(SRC_BONUS:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf
AR = ar crs

$(NAME): $(OBJS)
	$(AR) $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

bonus: $(OBJS_BONUS)
	$(AR) $(NAME) $^ 

all: $(NAME)

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean:	clean
	$(RM) $(NAME)		

re:	fclean all