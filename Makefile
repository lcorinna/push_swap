# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/11 14:43:07 by lcorinna          #+#    #+#              #
#    Updated: 2022/01/17 17:08:37 by lcorinna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_S = push_swap

PUSH_SWAP = push_swap.c rotate_down.c rotate_up.c swap_and_push.c pars.c \
working_with_a_list.c check.c sorting_center.c exit.c

OBJ_PS = $(PUSH_SWAP:.c=.o)

CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address # Leaks --atExit -- ./push_swap

PATH_LIBFT = ./libft/

LIBFT = libft.a 

all: $(LIBFT) $(NAME_S)

$(LIBFT):
	#make -C $(PATH_LIBFT)
	make bonus -C $(PATH_LIBFT)
	cp $(PATH_LIBFT)$(LIBFT) $(LIBFT)

$(NAME_S): $(OBJ_PS)
	gcc $(CFLAGS) $(LIBFT) $(OBJ_PS) -o $@

%.o: %.c push_swap.h Makefile
	gcc $(CFLAGS) -c $< -o $@	

clean:
	rm -f $(OBJ_PS) $(LIBFT)
	make clean -C $(PATH_LIBFT)

fclean: clean
	rm -rf $(NAME_S)
	make fclean -C $(PATH_LIBFT)

re: fclean all

.PHONY: all clean fclean re

# addprefix
# $@ - это имя создаваемой цели

# $< первое предварительное условие (обычно исходный файл)

# $?: Имена всех предварительных требований, 
# которые являются более новыми, чем цель, разделенные пробелами.

# $^: имена файлов всех предварительных требований, разделенные пробелами. 
# В этом списке удалены повторяющиеся имена файлов, 
# поскольку для большинства целей, таких как компиляция, 
# копирование и т. д., дубликаты не нужны.