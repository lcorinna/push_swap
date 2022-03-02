/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_and_push_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:47:58 by lcorinna          #+#    #+#             */
/*   Updated: 2022/03/02 18:01:08 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_sa_bonus(t_list **a)
{
	t_list	*tmp;

	if (*a != NULL && (*a)->next != NULL)
	{
		tmp = (*a)->next;
		(*a)->next = tmp->next;
		tmp->next = (*a);
		(*a) = tmp;
	}
}

void	ft_sb_bonus(t_list **b)
{
	t_list	*tmp;

	if (*b != NULL && (*b)->next != NULL)
	{
		tmp = (*b)->next;
		(*b)->next = tmp->next;
		tmp->next = (*b);
		(*b) = tmp;
	}
}

void	ft_ss_bonus(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (*a != NULL && (*a)->next != NULL)
	{
		tmp = (*a)->next;
		(*a)->next = tmp->next;
		tmp->next = (*a);
		(*a) = tmp;
	}
	if (*b != NULL && (*b)->next != NULL)
	{
		tmp = (*b)->next;
		(*b)->next = tmp->next;
		tmp->next = (*b);
		(*b) = tmp;
	}
}

void	ft_pb_bonus(t_list **a, t_list **b)
{
	t_list	*save;
	t_list	*tmp;

	if (*a != NULL)
	{
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
	}
}

void	ft_pa_bonus(t_list **a, t_list **b)
{
	t_list	*save;
	t_list	*tmp;

	if (*b != NULL)
	{
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
	}
}
