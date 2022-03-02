/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_up_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:52:43 by lcorinna          #+#    #+#             */
/*   Updated: 2022/03/02 17:58:57 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_ra_bonus(t_list **lst)
{
	t_list	*save;
	t_list	*tmp;

	if (*lst != NULL && (*lst)->next != NULL)
	{
		tmp = (*lst);
		save = (*lst)->next;
		while ((*lst)->next != NULL)
			(*lst) = (*lst)->next;
		tmp->next = NULL;
		(*lst)->next = tmp;
		(*lst) = save;
	}
}

void	ft_rb_bonus(t_list **lst)
{
	t_list	*save;
	t_list	*tmp;

	if (*lst != NULL && (*lst)->next != NULL)
	{
		tmp = (*lst);
		save = (*lst)->next;
		while ((*lst)->next != NULL)
			(*lst) = (*lst)->next;
		tmp->next = NULL;
		(*lst)->next = tmp;
		(*lst) = save;
	}
}

void	ft_rr_bonus(t_list **a, t_list **b)
{
	t_list	*save;
	t_list	*tmp;

	if (*a != NULL && (*a)->next != NULL)
	{
		tmp = (*a);
		save = (*a)->next;
		while ((*a)->next != NULL)
			(*a) = (*a)->next;
		tmp->next = NULL;
		(*a)->next = tmp;
		(*a) = save;
	}
	if (*b != NULL && (*b)->next != NULL)
	{
		tmp = (*b);
		save = (*b)->next;
		while ((*b)->next != NULL)
			(*b) = (*b)->next;
		tmp->next = NULL;
		(*b)->next = tmp;
		(*b) = save;
	}
}
