/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_center.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 16:17:56 by lcorinna          #+#    #+#             */
/*   Updated: 2022/01/26 11:20:59 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_for_two(t_list **lst)
{
	if ((*lst)->num > (*lst)->next->num)
		ft_sa(lst);
}

void	ft_sort_for_thee(t_list **lst)
{
	if ((*lst)->num < (*lst)->next->num \
	&& (*lst)->next->num < (*lst)->next->next->num) //123
		return ;
	if ((*lst)->num > (*lst)->next->num \
	&& (*lst)->next->num > (*lst)->next->next->num) //321 done
	{
		ft_sa(lst);
		ft_rra(lst);
	}
	else if ((*lst)->num > (*lst)->next->next->num && \
	(*lst)->next->num < (*lst)->next->next->num) //312 done
		ft_ra(lst);
	else if ((*lst)->num > (*lst)->next->next->num) //231 done
		ft_rra(lst);
	else if ((*lst)->next->num > (*lst)->next->next->num) //132 done
	{
		ft_rra(lst);
		ft_sa(lst);
	}
	else //213 done
		ft_sa(lst);
}

void	ft_sort_for_four(t_list **a, t_list **b, long long i)
{
	t_list		*tmp;

	tmp = *a;
	i = tmp->num;
	while (tmp->next)
	{
		if (tmp->next && i > tmp->next->num)
			i = tmp->next->num;
		tmp = tmp->next;
	}
	if (i == tmp->num)
		ft_rra(a);
	else
		ft_sorting_assistant(tmp, a, i);
	ft_pb(a, b);
	ft_sort_for_thee(a);
	ft_pa(a, b);
}

void	ft_sort_for_five(t_list **a, t_list **b, long long i)
{
	t_list		*tmp;

	tmp = *a;
	i = tmp->num;
	while (tmp->next)
	{
		if (tmp->next && i < tmp->next->num)
			i = tmp->next->num;
		tmp = tmp->next;
	}
	if (i == tmp->num)
		ft_rra(a);
	else
		ft_sorting_assistant(tmp, a, i);
	ft_pb(a, b);
	ft_sort_for_four(a, b, i);
	ft_pa(a, b);
	ft_ra(a);
}

void	ft_sorting_assistant(t_list *tmp, t_list **a, long long i)
{
	tmp = *a;
	while (i != tmp->num)
	{
		tmp = tmp->next;
		ft_ra(a);
	}
}
