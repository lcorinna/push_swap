# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/25 21:27:37 by lcorinna          #+#    #+#              #
#    Updated: 2022/01/27 13:14:06 by lcorinna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

LIST_1 = ft_lstadd_front_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c \
ft_split.c ft_substr.c ft_strlen.c ft_putstr_fd.c ft_lstsize_bonus.c

O_FILES = $(LIST_1:.c=.o)

O_FILES_FOR_BONUS = $(BONUS:.c=.o)

override ALL_O_FILES ?= $(O_FILES) 

all: $(NAME)

$(NAME): $(ALL_O_FILES)
	ar rcs $(NAME) $?

%.o: %.c libft.h Makefile
	gcc -Wall -Wextra -Werror -c $< -o $@

bonus:
	make ALL_O_FILES="$(O_FILES_FOR_BONUS)" all

clean:
	rm -f $(O_FILES) $(O_FILES_FOR_BONUS)

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME) bonus

.PHONY: all bonus clean fclean re