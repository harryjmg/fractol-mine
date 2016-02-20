#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgueguen <hgueguen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/17 10:43:17 by hgueguen          #+#    #+#              #
#    Updated: 2014/04/27 18:15:40 by hgueguen         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = 		fractol

W_FLAGS =	-Wall -Wextra

SRC_DIR =	src/
INC_DIR =	inc/

FILES =		main.c launch_fractol.c expose_hook.c key_hook.c motion_hook.c \
			fract_mandel.c fract_julia.c

SRC = 		$(addprefix $(SRC_DIR), $(FILES))
OBJ = 		$(SRC:.c=.o)

LIB = 		-L /usr/local/lib -lmlx -L libft/ -lft -framework OpenGL -framework AppKit 
INC =		-I /usr/local/include/ -I $(INC_DIR) -I libft/

LIBFT =		libft/libft.a

all:		$(NAME)

$(NAME):	$(OBJ) $(LIBFT)
			gcc -o $@ $^ $(INC) $(LIB)

$(LIBFT):
			make -C libft/

%.o:		%.c
			gcc -o $@ -c $^ $(W_FLAGS) $(INC)

clean:
			rm -f $(OBJ)

fclean: 	clean
			rm -f $(NAME)

re: 		fclean all

.PHONY:		all clean fclean re