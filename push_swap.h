/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:30:55 by lcorinna          #+#    #+#             */
/*   Updated: 2022/01/16 13:19:01 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h> //printf
# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

// typedef struct s_list
// {
// 	long long		content;
// 	struct s_list	*next;
// }	t_list;

void		ft_view_the_stack(t_list *a, t_list *b);  //promise me that before defending the project, you will kill me
long long	ft_number(char *done);
long long	ft_atoi_for_ps(char *s);
int			ft_pars(char **argv, int n);
void		ft_push_swap(t_list **a, t_list **b);
void		ft_rra(t_list **lst);
void		ft_rrb(t_list **lst);
void		ft_rrr(t_list **a, t_list **b);
void		ft_ra(t_list **lst);
void		ft_rb(t_list **lst);
void		ft_rr(t_list **a, t_list **b);
void		ft_sa(t_list **a);
void		ft_sb(t_list **b);
void		ft_ss(t_list **a, t_list **b);
void		ft_pb(t_list **a, t_list **b);
void		ft_pa(t_list **a, t_list **b);
t_list		*ft_lstnew_for_ps(long long content);
void		ft_lstclear_for_ps(t_list **lst);
void		ft_mk_lst(char **argv, t_list **lst, int n);
int			ft_strrchr_ps(char *s, int c);
int			ft_chek_on_sort(t_list **lst);
void		ft_sort_for_two(t_list **lst);
void		ft_sort_for_thee(t_list **lst);
void		ft_input_error(char *str, int i);
void		ft_malloc_not_allocate(char *str, int i);

#endif