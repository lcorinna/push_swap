/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 13:07:22 by lcorinna          #+#    #+#             */
/*   Updated: 2022/01/26 19:04:20 by lcorinna         ###   ########.fr       */
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
	write(2, "\nsort done\n\n\n", 13); //delete this line
	exit (19);
}
