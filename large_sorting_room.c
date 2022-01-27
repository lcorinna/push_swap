/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sorting_room.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 13:02:56 by lcorinna          #+#    #+#             */
/*   Updated: 2022/01/27 12:48:29 by lcorinna         ###   ########.fr       */
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
	{
		while (t_b)
		{
		t_a = *a;
			if (t_a->num > t_b->num && t_b->num > t_a_last->num)
			{
				if (t_b->index < 0 && t_a->next->index < 0) // -1 -1
					t_b->score = (t_b->index + t_a->next->index) * (-1);
				else if (t_b->index < 0 && t_a->next->index >= 0) // 1 -1
					t_b->score = (t_b->index * (-1)) + t_a->next->index;
				else if (t_b->index >= 0 && t_a->next->index < 0) // -1 1
					t_b->score = t_b->index + (t_a->next->index * (-1));
				else // 1 1
					t_b->score = t_b->index + t_a->next->index;
			}
			while (t_a->next)
			{
				if (t_a->num < t_b->num && t_b->num < t_a->next->num)
					working_on_score(&t_a, &t_b);
				t_a = t_a->next;
			}
			t_b = t_b->next;
		}
	}
	return (t_a_last);
}

void	ft_make_push_return(t_list **a, t_list **b, t_list	*t_a_last, int luck)
{
	t_list	*t_b;
	t_list	*t_a;
	int		turn_b;
	int		turn_a;

	t_b = *b;
	t_a = *a;
	luck = (*b)->score;
	turn_b = (*b)->index;
	while (*b)
	{
		if (luck > (*b)->score)
		{
			luck = (*b)->score;
			turn_b = (*b)->index;
			// printf("(*b)->num	%lld\n", (*b)->num); //del
		}
		*b = (*b)->next;
	}
	// printf("luck	%d\n", luck); //del
	*b = t_b;
	if (luck == (*b)->score && turn_b == (*b)->index \
	&& (*a)->num < (*b)->num && (*b)->num < t_a_last->num)
		ft_pa(a, b);
	else
	{
		while (*b)
		{
			*a = t_a;
			if (luck == (*b)->score && turn_b == (*b)->index \
			&& (*a)->num > (*b)->num && (*b)->num > t_a_last->num)
			{
				*b = t_b;
				while (turn_b != 0)
				{
					if (turn_b < 0)
					{
						// printf("turn_b	%d\n", turn_b);
						ft_rrb(b);
						turn_b++;
					}
					else
					{
						ft_rb(b);
						turn_b--;
					}
				}
				ft_pa(a, b);
				return ;
			}
			while ((*a)->next)
			{
				if (luck == (*b)->score && turn_b == (*b)->index && \
				(*a)->num < (*b)->num && (*b)->num < (*a)->next->num)
				{
					turn_a = (*a)->next->index;
					// printf("turn_a - %d\n", turn_a); //del 
					// printf("num_a	%lld\n", (*a)->num); //del
					// printf("(*b)->score	%d\n", (*b)->score); //del
				}
				(*a) = (*a)->next;
			}
			(*b) = (*b)->next;
		}
		*a = t_a;
		*b = t_b;
		while (turn_b != 0)
		{
			if (turn_b < 0)
			{
				ft_rrb(b);
				turn_b++;
			}
			else
			{
				ft_rb(b);
				turn_b--;
			}
		}
		while (turn_a != 0)
		{
			if (turn_a < 0)
			{
				ft_rra(a);
				// sleep (1);
				turn_a++;
			}
			else
			{
				ft_ra(a);
				turn_a--;
			}
		}
		ft_pa(a, b);
	}
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
		// ft_view_the_stack(*a, *b); //the_magic_of_visualization
		tmp_a_last = ft_adding_score(a, b);
		// ft_view_the_stack(*a, *b); //the_magic_of_visualization
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
	// ft_view_the_stack(*a, *b); //the_magic_of_visualization
	ft_return(a, b);
	while ((*a)->num != min)
		ft_ra(a);
}
