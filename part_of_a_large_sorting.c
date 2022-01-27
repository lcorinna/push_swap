/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part_of_a_large_sorting.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 13:56:36 by lcorinna          #+#    #+#             */
/*   Updated: 2022/01/27 12:34:22 by lcorinna         ###   ########.fr       */
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

void	ft_lift_up(t_list **lst, int flag, int size)
{
	t_list	*tmp;
	int		remains;
	int		i;

	tmp = *lst;
	size = ft_lstsize(tmp);
	i = size / 2 + 1;
	remains = size % 2;
	while (size != 1 && flag < i)
	{
		(*lst)->index += flag++;
		(*lst) = (*lst)->next;
	}
	if (size != 1 && remains == 1)
	{
		(*lst)->index += flag;
		(*lst) = (*lst)->next;
	}
	flag = flag * (-1) + 2;
	while (size != 1 && flag != 0)
	{
		(*lst)->index += flag++;
		(*lst) = (*lst)->next;
	}
	if (size == 1)
		(*lst)->index += flag;
	*lst = tmp;
}

void	working_on_score(t_list **t_a, t_list **t_b)
{
	if ((*t_b)->index < 0 && (*t_a)->next->index < 0) // -1 -1
		(*t_b)->score = ((*t_b)->index + (*t_a)->next->index) * (-1);
	else if ((*t_b)->index < 0 && (*t_a)->next->index >= 0) // 1 -1
		(*t_b)->score = ((*t_b)->index * (-1)) + (*t_a)->next->index;
	else if ((*t_b)->index >= 0 && (*t_a)->next->index < 0) // -1 1
		(*t_b)->score = (*t_b)->index + ((*t_a)->next->index * (-1));
	else // 1 1
		(*t_b)->score = (*t_b)->index + (*t_a)->next->index;
}
