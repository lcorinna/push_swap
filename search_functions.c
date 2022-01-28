/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 16:55:30 by lcorinna          #+#    #+#             */
/*   Updated: 2022/01/28 12:05:03 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_find_med(int *size)
{
	int	i;

	i = *size % 2;
	if (i == 0)
		*size = *size / 2 - 1;
	else
		*size = *size / 2;
}

void	ft_assign_an_index(t_list **a, int *j, int size)
{
	t_list			*tmp;
	long long		i;

	while (size)
	{
		tmp = *a;
		i = 2147483648;
		while (tmp)
		{
			if (tmp->index == -1 && i > tmp->num)
				i = tmp->num;
			if (tmp->next && tmp->next->index == -1 && i > tmp->next->num)
				i = tmp->next->num;
			tmp = tmp->next;
		}
		tmp = *a;
		while (tmp)
		{
			if (tmp->index == -1 && i == tmp->num)
				tmp->index += *j;
			tmp = tmp->next;
		}
		*j += 1;
		size--;
	}
}

void	ft_find_min_max(t_list **a, int *min, int *max, int *med)
{
	t_list	*tmp;
	int		j;
	int		size;

	j = 1;
	tmp = *a;
	size = ft_lstsize(tmp);
	ft_assign_an_index(a, &j, size);
	ft_find_med(&size);
	j -= 2;
	while (tmp)
	{
		if (tmp->index == 0)
			*min = tmp->num;
		else if (tmp->index == j)
			*max = tmp->num;
		else if (tmp->index == size)
			*med = tmp->num;
		tmp = tmp->next;
	}
}

void	ft_only_turn_b(t_list **b, t_storage **data)
{
	while ((*data)->turn_b != 0)
	{
		if ((*data)->turn_b < 0)
		{
			ft_rrb(b);
			(*data)->turn_b++;
		}
		else
		{
			ft_rb(b);
			(*data)->turn_b--;
		}
	}
}

void	ft_only_turn_a(t_list **a, t_storage **data)
{
	while ((*data)->turn_a != 0)
	{
		if ((*data)->turn_a < 0)
		{
			ft_rra(a);
			(*data)->turn_a++;
		}
		else
		{
			ft_ra(a);
			(*data)->turn_a--;
		}
	}
}
