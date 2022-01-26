/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_up.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:52:43 by lcorinna          #+#    #+#             */
/*   Updated: 2022/01/18 18:42:07 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_list **lst)
{
	t_list	*save;
	t_list	*tmp;

	tmp = (*lst);
	save = (*lst)->next;
	while ((*lst)->next != NULL)
		(*lst) = (*lst)->next;
	tmp->next = NULL;
	(*lst)->next = tmp;
	(*lst) = save;
	ft_putstr_fd("ra\n", 1);
}

void	ft_rb(t_list **lst)
{
	t_list	*save;
	t_list	*tmp;

	tmp = (*lst);
	save = (*lst)->next;
	while ((*lst)->next != NULL)
		(*lst) = (*lst)->next;
	tmp->next = NULL;
	(*lst)->next = tmp;
	(*lst) = save;
	ft_putstr_fd("rb\n", 1);
}

void	ft_rr(t_list **a, t_list **b)
{
	t_list	*save;
	t_list	*tmp;

	tmp = (*a);
	save = (*a)->next;
	while ((*a)->next != NULL)
		(*a) = (*a)->next;
	tmp->next = NULL;
	(*a)->next = tmp;
	(*a) = save;
	tmp = (*b);
	save = (*b)->next;
	while ((*b)->next != NULL)
		(*b) = (*b)->next;
	tmp->next = NULL;
	(*b)->next = tmp;
	(*b) = save;
	ft_putstr_fd("rr\n", 1);
}
