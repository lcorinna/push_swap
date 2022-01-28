/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_second_part_b_s.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 13:51:28 by lcorinna          #+#    #+#             */
/*   Updated: 2022/01/28 12:04:38 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lowest_score(t_list **b, int *luck, t_storage **data)
{
	*luck = (*b)->score;
	*data = ft_lstnew_for_ps_two((*b)->index);
	while (*b)
	{
		if (*luck > (*b)->score)
		{
			*luck = (*b)->score;
			(*data)->turn_b = (*b)->index;
		}
		*b = (*b)->next;
	}
}

void	ft_turn_both_value(t_list **a, t_list **b, t_storage **data)
{
	if ((*data)->turn_b != 0 && (*data)->turn_a != 0)
	{
		if ((*data)->turn_b < 0 && (*data)->turn_a < 0)
		{
			while ((*data)->turn_b < 0 && (*data)->turn_a < 0)
			{
				ft_rrr(a, b);
				(*data)->turn_a++;
				(*data)->turn_b++;
			}
		}
		if ((*data)->turn_b > 0 && (*data)->turn_a > 0)
		{
			while ((*data)->turn_b > 0 && (*data)->turn_a > 0)
			{
				ft_rr(a, b);
				(*data)->turn_a--;
				(*data)->turn_b--;
			}	
		}
	}
	if ((*data)->turn_b != 0)
		ft_only_turn_b(b, data);
	if ((*data)->turn_a != 0)
		ft_only_turn_a(a, data);
}

void	ft_spin_stack_a(t_list **a, t_list **b, t_storage **data, int luck)
{
	while ((*a)->next)
	{
		if (luck == (*b)->score && (*data)->turn_b == (*b)->index \
		&& (*a)->num < (*b)->num && (*b)->num < (*a)->next->num)
			(*data)->turn_a = (*a)->next->index;
		(*a) = (*a)->next;
	}
}

void	ft_part_return(t_list **a, t_list **b, t_storage **data, int luck)
{
	t_list		*t_b;
	t_list		*t_a;

	t_b = *b;
	t_a = *a;
	while (*b)
	{
		*a = t_a;
		if (luck == (*b)->score && (*data)->turn_b == (*b)->index \
		&& (*a)->num > (*b)->num && (*b)->num > (*data)->a_last)
		{
			*b = t_b;
			ft_only_turn_b(b, data);
			ft_pa(a, b);
			return ;
		}
		ft_spin_stack_a(a, b, data, luck);
		(*b) = (*b)->next;
	}
	*a = t_a;
	*b = t_b;
	ft_turn_both_value(a, b, data);
	ft_pa(a, b);
}
