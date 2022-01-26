/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_and_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:47:58 by lcorinna          #+#    #+#             */
/*   Updated: 2022/01/26 17:34:44 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_list **a)
{
	t_list	*tmp;

	tmp = (*a)->next;
	(*a)->next = tmp->next;
	tmp->next = (*a);
	(*a) = tmp;
	ft_putstr_fd("sa\n", 1);
}

void	ft_sb(t_list **b)
{
	t_list	*tmp;

	tmp = (*b)->next;
	(*b)->next = tmp->next;
	tmp->next = (*b);
	(*b) = tmp;
	ft_putstr_fd("sb\n", 1);
}

void	ft_ss(t_list **a, t_list **b)
{
	t_list	*tmp;

	tmp = (*a)->next;
	(*a)->next = tmp->next;
	tmp->next = (*a);
	(*a) = tmp;
	tmp = (*b)->next;
	(*b)->next = tmp->next;
	tmp->next = (*b);
	(*b) = tmp;
	ft_putstr_fd("ss\n", 1);
}

void	ft_pb(t_list **a, t_list **b)
{
	t_list	*save;
	t_list	*tmp;

	tmp = ft_lstnew_for_ps((*a)->num);
	ft_lstadd_front(b, tmp);
	if ((*a)->next == NULL)
	{
		free(*a);
		*a = NULL;
	}
	else if ((*a)->next != NULL)
	{
		save = (*a)->next;
		free(*a);
		(*a) = save;
	}
	ft_putstr_fd("pb\n", 1);
}

void	ft_pa(t_list **a, t_list **b)
{
	t_list	*save;
	t_list	*tmp;

	tmp = ft_lstnew_for_ps((*b)->num);
	ft_lstadd_front(a, tmp);
	if ((*b)->next == NULL)
	{
		free(*b);
		*b = NULL;
	}
	else if ((*b)->next != NULL)
	{
		save = (*b)->next;
		free(*b);
		(*b) = save;
	}
	ft_putstr_fd("pa\n", 1);
}
