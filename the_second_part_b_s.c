/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_second_part_b_s.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 13:51:28 by lcorinna          #+#    #+#             */
/*   Updated: 2022/01/27 18:10:10 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lowest_score(t_list **b, int *luck, int *turn_b)
{
	*luck = (*b)->score;
	*turn_b = (*b)->index;
	while (*b)
	{
		if (*luck > (*b)->score)
		{
			*luck = (*b)->score;
			*turn_b = (*b)->index;
		}
		*b = (*b)->next;
	}
}

void	ft_only_turn_b(t_list **b, int *turn_b)
{
	while ((*turn_b) != 0)
	{
		if ((*turn_b) < 0)
		{
			ft_rrb(b);
			(*turn_b)++;
		}
		else
		{
			ft_rb(b);
			(*turn_b)--;
		}
	}
}

void	ft_only_turn_a(t_list **a, int *turn_a)
{
	while ((*turn_a) != 0)
	{
		if ((*turn_a) < 0)
		{
			ft_rra(a);
			(*turn_a)++;
		}
		else
		{
			ft_ra(a);
			(*turn_a)--;
		}
	}
}

void	ft_turn_both_value(t_list **a, t_list **b, int turn_a, int turn_b)
{
	if (turn_b != 0 && turn_a != 0)
	{
		if (turn_b < 0 && turn_a < 0)
		{
			while (turn_b < 0 && turn_a < 0)
			{
				ft_rrr(a, b);
				turn_a++;
				turn_b++;
			}
		}
		if (turn_b > 0 && turn_a > 0)
		{
			while (turn_b > 0 && turn_a > 0)
			{
				ft_rr(a, b);
				turn_a--;
				turn_b--;
			}	
		}
	}
	if (turn_b != 0)
		ft_only_turn_b(b, &turn_b);
	if (turn_a != 0)
		ft_only_turn_a(a, &turn_a);
}

void	ft_make_push_return(t_list **a, t_list **b, t_list	*a_last, int luck)
{
	t_list	*t_b;
	t_list	*t_a;
	int		turn_b;
	int		turn_a;

	t_b = *b;
	t_a = *a;
	ft_lowest_score(b, &luck, &turn_b);
	*b = t_b;
	if (luck == (*b)->score && turn_b == (*b)->index \
	&& (*a)->num < (*b)->num && (*b)->num < a_last->num)
		ft_pa(a, b);
	else
	{
		while (*b)
		{
			*a = t_a;
			if (luck == (*b)->score && turn_b == (*b)->index \
			&& (*a)->num > (*b)->num && (*b)->num > a_last->num)
			{
				*b = t_b;
				ft_only_turn_b(b, &turn_b);
				ft_pa(a, b);
				return ;
			}
			while ((*a)->next)
			{
				if (luck == (*b)->score && turn_b == (*b)->index && \
				(*a)->num < (*b)->num && (*b)->num < (*a)->next->num)
					turn_a = (*a)->next->index;
				(*a) = (*a)->next;
			}
			(*b) = (*b)->next;
		}
		*a = t_a;
		*b = t_b;
		ft_turn_both_value(a, b, turn_a, turn_b);
		ft_pa(a, b);
	}
}
