# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsemerar <gsemerar@student.42roma.it>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/21 08:22:46 by gsemerar          #+#    #+#              #
#    Updated: 2022/04/04 19:58:27 by gsemerar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name
NAME := so_long

# Directories
DIR_SRCS		:= ./src
DIR_FT_PRINTF	:= $(DIR_SRCS)/ft_printf
DIR_INCLUDES 	:= $(DIR_SRCS)/includes
DIR_MLX			:= ./mlx_linux
DIR_BUILD		:= ./build

# Libraries
LIB_FT_PRINTF	:= $(DIR_FT_PRINTF)/libftprintf.a
LIB_MLX			:= $(DIR_MLX)/libmlx_Linux.a

# Implicit rules
DEBUG			:= -g
# CFLAGS			:= $(DEBUG) -Werror -Wall -Wextra
CFLAGS			:= $(DEBUG)
CC				:= gcc

# Cmd
RM				:= rm -rf

# Sources
SRCS 			:= $(shell find $(DIR_SRCS) -maxdepth 1 -name '*.c')

# Objects
OBJS 			:= $(SRCS:%.c=$(DIR_BUILD)/%.o)

# Includes
$(DIR_INCLUDES)	+= $(DIR_MLX)
INCLUDES 		:= $(addprefix -I,$(DIR_INCLUDES))
MLX_INCLUDES	:= -L$(DIR_MLX) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) bonus -C $(DIR_FT_PRINTF)
	$(CC) $(OBJS) $(LIB_FT_PRINTF) $(LIB_MLX) $(INCLUDES) $(MLX_INCLUDES) -o $@

$(DIR_BUILD)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I/usr/include -I$(DIR_MLX) -O3 -c $< -o $@

clean:
	$(MAKE) clean -C $(DIR_FT_PRINTF)
	$(RM) $(OBJS) $(DIR_BUILD)

fclean: clean
	$(MAKE) fclean -C $(DIR_FT_PRINTF)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
