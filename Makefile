# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/11 14:43:07 by lcorinna          #+#    #+#              #
#    Updated: 2022/01/28 14:23:02 by lcorinna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_S = push_swap

PUSH_SWAP = push_swap.c rotate_down.c rotate_up.c swap_and_push.c pars.c \
working_with_a_list.c check.c sorting_center.c exit.c large_sorting_room.c \
search_functions.c the_first_part_b_s.c the_second_part_b_s.c 

OBJ_PS = $(PUSH_SWAP:.c=.o)

CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=address # Leaks --atExit -- ./push_swap

PATH_LIBFT = ./libft/

LIBFT = libft.a 

all: libmake $(NAME_S)

libmake: 
	make -C $(PATH_LIBFT)
	@cp $(PATH_LIBFT)$(LIBFT) $(LIBFT)
		
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
