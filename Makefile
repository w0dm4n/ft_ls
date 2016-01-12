# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frmarinh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/17 08:34:59 by frmarinh          #+#    #+#              #
#    Updated: 2016/01/12 19:11:57 by frmarinh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRCS_NAME = main.c print_error.c

LIB_FOLDER = libft/

O_NAME = $(SRCS_NAME:.c=.o)

FLAGS = -Wall -Wextra -Werror

INCLUDE_FOLDER = libft/includes/

all: $(NAME)

$(NAME):
	@make -C libft/ fclean
	@make -C libft/
	@gcc $(FLAGS) -I $(INCLUDE_FOLDER) -c $(SRCS_NAME)
	@gcc -o $(NAME) $(O_NAME) -L $(LIB_FOLDER) -lft

clean:
	@rm -rf $(O_NAME)

fclean: clean
	@rm -rf $(NAME)

re:		fclean all

.PHONY: all clean fclean re
