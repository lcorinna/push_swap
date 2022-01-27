/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 13:07:22 by lcorinna          #+#    #+#             */
/*   Updated: 2022/01/27 18:05:59 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_input_error(char *str, int i)
{	
	ft_putstr_fd(str, i);
	exit (5);
}

void	ft_malloc_not_allocate(char *str, int i)
{
	ft_putstr_fd(str, i);
	exit (13);
}

void	ft_sort_done(t_list **lst)
{
	ft_lstclear_for_ps(lst);
	exit (19);
}
