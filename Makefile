# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ohelly <ohelly@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/26 19:03:58 by ohelly            #+#    #+#              #
#    Updated: 2019/06/12 17:13:59 by ohelly           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = gcc
MAKE = make
FLAGS = -Wall -Wextra -Werror
FRAMEWORKS = -framework OpenGL -framework AppKit
CFILES = \
		srcs/main.c \
		srcs/mandelbrot.c \
		srcs/additional.c \
		srcs/burningship.c \
		srcs/clear.c \
		srcs/ft_empty.c \
		srcs/julia.c \
		srcs/key.c 
OFILES = $(CFILES:%.c=%.o)

LIBINC = libft/includes
LIBPATH = libft/
FT = ft
LFTPATH = $(LIBPATH)
LFT = $(addprefix lib, $(addsuffix .a, $(FT)))
LIBFT = -L$(LFTPATH) -l$(FT)
MKFT = $(MAKE) -C $(LFTPATH)

MLX = mlx
LMLXPATH = minilib/
LMLX = $(addprefix lib, $(addsuffix .a, $(MLX)))
LIBMLX = -L$(LMLXPATH) -l$(MLX)
MKMLX = $(MAKE) -C $(LMLXPATH)

SRC = $(CFILES)
OBJS = $(OFILES)

INC = includes/
INCLUDES = -I$(LIBINC) -I$(LMLXPATH) -I$(INC)
LIB = -lm $(LIBFT) $(LIBMLX)

all: $(NAME)

$(NAME) : $(LFT) $(LMLX) $(OBJS)
		$(CC) -o $(NAME) $(INCLUDES) $(LIB) $(FRAMEWORKS) $(OBJS)

%.o: %.c
		$(CC) $(FLAGS) -o $@ $(INCLUDES) -c $<

$(LFT):
		$(MKFT)

$(LMLX):
		$(MKMLX)

clean:
		$(MKFT) clean
		$(MKMLX) clean
		rm -rf $(OBJS)

fclean: clean
		$(MKFT) fclean
		rm -rf $(NAME)

re: fclean all