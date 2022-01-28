/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:30:55 by lcorinna          #+#    #+#             */
/*   Updated: 2022/01/28 12:16:32 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// # include <stdio.h> //printf
# include "libft/libft.h"

typedef struct s_storage
{
	int	a_last;
	int	turn_b;
	int	turn_a;
}	t_storage;

// void		ft_view_the_stack(t_list *a, t_list *b);
void		ft_push_swap(t_list **a, t_list **b);

long long	ft_number(char *done);
long long	ft_atoi_for_ps(char *s);
int			ft_pars(char **argv, int n);

void		ft_sa(t_list **a);
void		ft_sb(t_list **b);
void		ft_ss(t_list **a, t_list **b);
void		ft_pb(t_list **a, t_list **b);
void		ft_pa(t_list **a, t_list **b);

void		ft_ra(t_list **lst);
void		ft_rb(t_list **lst);
void		ft_rr(t_list **a, t_list **b);

void		ft_rra(t_list **lst);
void		ft_rrb(t_list **lst);
void		ft_rrr(t_list **a, t_list **b);

t_list		*ft_lstnew_for_ps(long long content);
t_storage	*ft_lstnew_for_ps_two(int content);
void		ft_lstclear_for_ps(t_list **lst);
void		ft_mk_lst(char **argv, t_list **lst, int n);

int			ft_strrchr_ps(char *s, int c);
int			ft_chek_on_sort(t_list **lst);

void		ft_sort_for_two(t_list **lst);
void		ft_sort_for_thee(t_list **lst);
void		ft_sort_for_four(t_list **a, t_list **b, long long i);
void		ft_sort_for_five(t_list **a, t_list **b, long long i);
void		ft_sorting_assistant(t_list *tmp, t_list **a, long long i);

void		ft_input_error(char *str, int i);
void		ft_malloc_not_allocate(char *str, int i);
void		ft_sort_done(t_list **lst);

void		ft_large_sorting(t_list **a, t_list **b);
void		ft_make_push(t_list **a, t_list **b, int med, int max);
void		ft_return(t_list **a, t_list **b);
t_list		*ft_adding_score(t_list **a, t_list **b);
void		ft_make_push_return(t_list **a, t_list **b, \
												t_list	*t_a_last, int luck);

void		ft_find_med(int *size);
void		ft_assign_an_index(t_list **a, int *j, int size);
void		ft_find_min_max(t_list **a, int *min, int *max, int *med);
void		ft_only_turn_b(t_list **b, t_storage **data);
void		ft_only_turn_a(t_list **a, t_storage **data);

void		ft_lift_up(t_list **b, int flag, int size);
void		ft_zero_index(t_list **a);
void		ft_working_on_score(t_list **t_a, t_list **t_b);
void		ft_changing_the_index(t_list **lst, int flag, int i, int remains);
void		ft_assistant_for_score(t_list **b, t_list **a, t_list **t_a_last);

void		ft_lowest_score(t_list **b, int *luck, t_storage **data);
void		ft_turn_both_value(t_list **a, t_list **b, t_storage **data);
void		ft_part_return(t_list **a, t_list **b, t_storage **data, int luck);
void		ft_spin_stack_a(t_list **a, t_list **b, t_storage **data, int luck);

#endif
