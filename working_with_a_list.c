/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   working_with_a_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:50:14 by lcorinna          #+#    #+#             */
/*   Updated: 2022/01/17 14:39:35 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew_for_ps(long long content)
{
	t_list	*f_element;

	f_element = (t_list *) malloc(sizeof(t_list));
	if (f_element == NULL)
		ft_malloc_not_allocate("Error malloc\n", 2);
	(*f_element).content = content;
	f_element->next = NULL;
	return (f_element);
}

void	ft_lstclear_for_ps(t_list **lst)
{
	t_list	*next;

	while (*lst)
	{
		next = (*lst)->next;
		free(*lst);
		*lst = next;
	}
	*lst = NULL;
}

void	ft_mk_lst(char **argv, t_list **lst, int n)
{
	t_list	*new;

	if (n == 1)
		*lst = ft_lstnew_for_ps(ft_atoi_for_ps(argv[n++]));
	while (argv[n])
	{
		new = ft_lstnew_for_ps(ft_atoi_for_ps(argv[n++]));
		if (new == NULL)
		{
			ft_lstclear_for_ps(lst);
			ft_malloc_not_allocate("Error malloc\n", 2);
		}
		ft_lstadd_back(lst, new);
	}
}
