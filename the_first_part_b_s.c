/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_first_part_b_s.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 13:56:36 by lcorinna          #+#    #+#             */
/*   Updated: 2022/01/27 18:05:31 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_zero_index(t_list **a)
{
	t_list	*tmp;

	tmp = *a;
	while (*a)
	{
		(*a)->index = -1;
		*a = (*a)->next;
	}
	*a = tmp;
}

void	ft_changing_the_index(t_list **lst, int flag, int i, int remains)
{
	while (flag < i)
	{
		(*lst)->index += flag++;
		(*lst) = (*lst)->next;
	}
	if (remains == 1)
	{
		(*lst)->index += flag;
		(*lst) = (*lst)->next;
	}
	flag = flag * (-1) + 2;
	while (flag != 0)
	{
		(*lst)->index += flag++;
		(*lst) = (*lst)->next;
	}
}

void	ft_lift_up(t_list **lst, int flag, int size)
{
	t_list	*tmp;
	int		remains;
	int		i;

	tmp = *lst;
	size = ft_lstsize(tmp);
	i = size / 2 + 1;
	remains = size % 2;
	if (size != 1)
		ft_changing_the_index(lst, flag, i, remains);
	else if (size == 1)
		(*lst)->index += flag;
	*lst = tmp;
}

void	ft_working_on_score(t_list **t_a, t_list **t_b)
{
	if ((*t_b)->index < 0 && (*t_a)->next->index < 0)
		(*t_b)->score = ((*t_b)->index + (*t_a)->next->index) * (-1);
	else if ((*t_b)->index < 0 && (*t_a)->next->index >= 0)
		(*t_b)->score = ((*t_b)->index * (-1)) + (*t_a)->next->index;
	else if ((*t_b)->index >= 0 && (*t_a)->next->index < 0)
		(*t_b)->score = (*t_b)->index + ((*t_a)->next->index * (-1));
	else
		(*t_b)->score = (*t_b)->index + (*t_a)->next->index;
}

void	ft_assistant_for_score(t_list **b, t_list **a, t_list **t_a_last)
{
	t_list	*t_a;
	t_list	*t_b;

	t_b = *b;
	while (t_b)
	{
		t_a = *a;
		if (t_a->num > t_b->num && t_b->num > (*t_a_last)->num)
			ft_working_on_score(&t_a, &t_b);
		while (t_a->next)
		{
			if (t_a->num < t_b->num && t_b->num < t_a->next->num)
				ft_working_on_score(&t_a, &t_b);
			t_a = t_a->next;
		}
		t_b = t_b->next;
	}
}
