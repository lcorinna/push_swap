/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 22:40:44 by lcorinna          #+#    #+#             */
/*   Updated: 2022/02/27 19:32:15 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "get_next_line.h"
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	long long		num;
	int				index;
	int				score;
	struct s_list	*next;
}	t_list;

void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char *s, char c);
size_t	ft_strlen(const char *r);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);

#endif