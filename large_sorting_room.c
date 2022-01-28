/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sorting_room.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 13:02:56 by lcorinna          #+#    #+#             */
/*   Updated: 2022/01/28 12:02:53 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_adding_score(t_list **a, t_list **b)
{
	t_list	*t_a;
	t_list	*t_a_last;
	t_list	*t_b;
	int		i;

	t_b = *b;
	t_a = *a;
	t_a_last = ft_lstlast(t_a);
	i = ft_lstsize(t_a);
	if (i == 1)
		return (t_a_last);
	else if (t_a->num > t_b->num && t_b->num > t_a_last->num)
		t_b->score = t_b->index + t_a->index;
	else
		ft_assistant_for_score(b, a, &t_a_last);
	return (t_a_last);
}

void	ft_return(t_list **a, t_list **b)
{
	t_list	*tmp_a;
	t_list	*tmp_b;
	t_list	*tmp_a_last;
	int		i;
	int		size;

	tmp_a = (*a);
	tmp_b = (*b);
	i = 1;
	size = 0;
	while (*b)
	{
		ft_zero_index(a);
		ft_zero_index(b);
		ft_lift_up(a, i, size);
		ft_lift_up(b, i, size);
		tmp_a_last = ft_adding_score(a, b);
		ft_make_push_return(a, b, tmp_a_last, i);
	}
}

void	ft_make_push(t_list **a, t_list **b, int med, int max)
{
	t_list	*tmp;

	tmp = *a;
	while (tmp->next->next->next != NULL)
	{
		if (tmp->num == max || tmp->index == 0 || tmp->num == med)
			ft_rra(&tmp);
		else
		{
			ft_pb(&tmp, b);
			if ((*b)->next != NULL && (*b)->num > med)
				ft_rb(b);
		}
	}
	(*a) = tmp;
	ft_sort_for_thee(a);
	ft_ra(a);
}

void	ft_large_sorting(t_list **a, t_list **b)
{
	int	min;
	int	max;
	int	med;

	ft_find_min_max(a, &min, &max, &med);
	ft_make_push(a, b, med, max);
	ft_return(a, b);
	while ((*a)->num != min)
		ft_ra(a);
}

void	ft_make_push_return(t_list **a, t_list **b, t_list	*a_last, int luck)
{
	t_list		*t_b;
	t_storage	*data;

	t_b = *b;
	ft_lowest_score(b, &luck, &data);
	data->a_last = a_last->num;
	*b = t_b;
	if (luck == (*b)->score && data->turn_b == (*b)->index \
	&& (*a)->num < (*b)->num && (*b)->num < data->a_last)
		ft_pa(a, b);
	else
		ft_part_return(a, b, &data, luck);
	free (data);
}
