# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsemerar <gsemerar@student.42roma.it>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/06 09:51:37 by ajordan-          #+#    #+#              #
#    Updated: 2022/02/25 11:57:00 by gsemerar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Variables

NAME	= libftprintf.a
INCLUDE	= includes
LIBFT	= libft
CC		= gcc
OPTION	= -c -I $(INCLUDE)
CFLAGS	= -Wall -Werror -Wextra $(OPTION)
RM		= rm -f
AR		= ar rcs

#Sources

SRC		=	src/ft_printf.c				\
			src/printf_utils.c			\
			src/format_utils.c			\
			src/print_chars.c			\
			src/char_utils.c			\
			src/print_pointer.c			\
			src/pointer_utils.c			\
			src/print_num.c				\
			src/num_utils.c				\
			src/num_unsigned_utils.c	\
			src/num_hex_utils.c			\
			src/hex_utils.c

OBJ		=	$(SRC:.c=.o)

###

all:		$(NAME)

$(NAME):	$(OBJ)
			make bonus -C $(LIBFT)
			cp libft/libft.a $(NAME)
			$(AR) $(NAME) $(OBJ)

bonus:		all

clean:
			$(RM) $(OBJ)
			make clean -C $(LIBFT)

fclean:		clean
			$(RM) $(NAME)
			$(RM) $(LIBFT)/libft.a

re:			fclean all

.PHONY:		all clean fclean re bonus
