/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_center.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 16:17:56 by lcorinna          #+#    #+#             */
/*   Updated: 2022/01/15 20:14:06 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_for_two(t_list **lst)
{
	if ((*lst)->content > (*lst)->next->content)
		ft_sa(lst);
}

void	ft_sort_for_thee(t_list **lst)
{
	if ((*lst)->content > (*lst)->next->content \
	&& (*lst)->next->content > (*lst)->next->next->content)
	{
		ft_ra(lst);
		ft_ra(lst);
		ft_lstclear_for_ps(lst);
		return ;
	}
}
