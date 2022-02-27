/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_down.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:53:46 by lcorinna          #+#    #+#             */
/*   Updated: 2022/02/27 18:48:26 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_list **lst)
{
	t_list	*save;
	t_list	*tmp;

	if (*lst != NULL && (*lst)->next != NULL)
	{
		save = (*lst);
		while ((*lst)->next->next)
			(*lst) = (**lst).next;
		tmp = (*lst)->next;
		(*lst)->next = NULL;
		(*lst) = tmp;
		(*lst)->next = save;
		ft_putstr_fd("rra\n", 1);
	}
}

void	ft_rrb(t_list **lst)
{
	t_list	*save;
	t_list	*tmp;

	if (*lst != NULL && (*lst)->next != NULL)
	{
		save = (*lst);
		while ((*lst)->next->next)
			(*lst) = (**lst).next;
		tmp = (*lst)->next;
		(*lst)->next = NULL;
		(*lst) = tmp;
		(*lst)->next = save;
		ft_putstr_fd("rrb\n", 1);
	}
}

void	ft_rrr(t_list **a, t_list **b)
{
	t_list	*save;
	t_list	*tmp;

	if (*a != NULL && *b != NULL && (*a)->next != NULL && (*b)->next != NULL)
	{
		save = (*a);
		while ((*a)->next->next)
			(*a) = (**a).next;
		tmp = (*a)->next;
		(*a)->next = NULL;
		(*a) = tmp;
		(*a)->next = save;
		save = (*b);
		while ((*b)->next->next)
			(*b) = (**b).next;
		tmp = (*b)->next;
		(*b)->next = NULL;
		(*b) = tmp;
		(*b)->next = save;
		ft_putstr_fd("rrr\n", 1);
	}
}
