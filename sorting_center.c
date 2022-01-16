/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_center.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 16:17:56 by lcorinna          #+#    #+#             */
/*   Updated: 2022/01/16 18:47:38 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_for_two(t_list **lst)
{
	if ((*lst)->content > (*lst)->next->content)
		ft_sa(lst);
}

void	ft_sort_for_thee(t_list **lst)
{
	if ((*lst)->content > (*lst)->next->content \
	&& (*lst)->next->content > (*lst)->next->next->content) //321 done
	{
		ft_sa(lst);
		ft_rra(lst);
	}
	else if ((*lst)->content > (*lst)->next->next->content && \
	(*lst)->next->content < (*lst)->next->next->content) //312 done
		ft_ra(lst);
	else if ((*lst)->content > (*lst)->next->next->content) //231 done
		ft_rra(lst);
	else if ((*lst)->next->content > (*lst)->next->next->content) //132 done
	{
		ft_rra(lst);
		ft_sa(lst);
	}
	else //213 done
		ft_sa(lst);
}

void	ft_sort_for_four(t_list **a, t_list **b)
{
	t_list		*tmp;
	long long	i;

	tmp = *a;
	i = tmp->content;
	while (tmp)
	{
		if (tmp->next && i > tmp->next->content)
			i = tmp->next->content;
		tmp = tmp->next;
	}
	tmp = *a;
	while (i != tmp->content)
	{
		tmp = tmp->next;
		ft_ra(a);
	}
	ft_pb(a, b);
	ft_sort_for_thee(a);
	ft_pa(a, b);
}

void	ft_sort_for_five(t_list **a, t_list **b)
{
	t_list		*tmp;
	long long	i;

	tmp = *a;
	i = tmp->content;
	while (tmp)
	{
		if (tmp->next && i < tmp->next->content)
			i = tmp->next->content;
		tmp = tmp->next;
	}
	tmp = *a;
	while (i != tmp->content)
	{
		tmp = tmp->next;
		ft_ra(a);
	}
	ft_pb(a, b);
	ft_sort_for_four(a, b);
	ft_pa(a, b);
	ft_ra(a);
}
