# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frmarinh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/17 08:34:59 by frmarinh          #+#    #+#              #
#    Updated: 2016/01/21 04:20:48 by frmarinh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRCS_NAME = main.c print_error.c add_flags.c get_current_dir.c print_dir.c get_specified_dir.c utils.c utils_suite.c print_line.c utils_suite_ext.c print_dir_ext.c print_recursive.c range_by_t_flags.c utils_suite_ext_2.c get_permissions.c print_dir_suite.c colored_line.c

LIB_FOLDER = libft/

O_NAME = $(SRCS_NAME:.c=.o)

FLAGS = -Wall -Wextra -Werror -ggdb -O3

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
