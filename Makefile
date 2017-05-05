#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/17 19:25:28 by mkyianyt          #+#    #+#              #
#    Updated: 2017/02/27 17:06:26 by mkyianyt         ###   ########.fr        #
#                                                                              #
#******************************************************************************#
NAME = fractol

SRC = choose.c color.c draw.c enhance.c get_iterations.c init.c init_fractals.c\
	  main.c move.c run.c validate.c zoom.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra

ATTACH = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[32;1mBuilding archive babyyyy...\033[0m"
	@make -C libft
	@gcc $(CFLAGS) -o $(NAME) -L libft -lft $(OBJ) $(ATTACH)
	@echo "\033[33;1mAbra Kadabra!!!\033[0m"

.c.o:
	@echo "\033[34;3mGeting funky with\033[0m $<"
	@gcc $(CFLAGS) -c $< -o $@ \

clean:
	@echo "\033[31mRemoving objects...\033[0m"
	@make -C libft/ clean
	@rm -f $(OBJ)

fclean: clean
	@echo "\033[31mYO YO YO!!!\033[0m"
	@make -C libft/ fclean
	@rm -f $(NAME)

re: fclean all

norme:
	norminette $(SRC)