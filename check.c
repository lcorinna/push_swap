/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 16:00:04 by lcorinna          #+#    #+#             */
/*   Updated: 2022/01/26 11:18:41 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_chek_on_sort(t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	while (tmp && tmp->next)
	{
		if (tmp->next && tmp->num > tmp->next->num)
			return (0);
		tmp = tmp->next;
	}
	ft_sort_done(lst);
	return (1);
}

int	ft_strrchr_ps(char *s, int c)
{
	char	*a;
	int		i;
	char	m;

	m = (char) c;
	i = 0;
	a = (char *) s;
	while (a[i])
		i++;
	if (c == '\0')
		return (1);
	while (i-- != 0)
	{
		if (a[i] == m)
			return (1);
		if (a[i + 1] == m)
			return (1);
	}
	return (0);
}
