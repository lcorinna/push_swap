/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_down_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:53:46 by lcorinna          #+#    #+#             */
/*   Updated: 2022/03/02 19:08:52 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_rra_bonus(t_list **lst)
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
	}
}

void	ft_rrb_bonus(t_list **lst)
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
	}
}

void	ft_rrr_bonus(t_list **a, t_list **b)
{
	t_list	*save;
	t_list	*tmp;

	if (*a != NULL && (*a)->next != NULL)
	{
		save = (*a);
		while ((*a)->next->next)
			(*a) = (**a).next;
		tmp = (*a)->next;
		(*a)->next = NULL;
		(*a) = tmp;
		(*a)->next = save;
	}
	if (*b != NULL && (*b)->next != NULL)
	{
		save = (*b);
		while ((*b)->next->next)
			(*b) = (**b).next;
		tmp = (*b)->next;
		(*b)->next = NULL;
		(*b) = tmp;
		(*b)->next = save;
	}
}

void	ft_command_not_found(char **arr, int i, t_list **a, t_list **b)
{
	i = 0;
	ft_putstr_fd("Error\n", 2);
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	ft_lstclear_for_ps(a);
	ft_lstclear_for_ps(b);
	exit (1);
}
