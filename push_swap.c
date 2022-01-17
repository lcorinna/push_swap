/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:13:04 by lcorinna          #+#    #+#             */
/*   Updated: 2022/01/17 17:10:05 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_view_the_stack(t_list *a, t_list *b) //promise me that before defending the project, you will kill me
{
	int		line;
	int		i;
	int		j;

	i = ft_lstsize(a);
	j = ft_lstsize(b);
	if (j > i)
		i = j;
	line = 0;
	printf("__________________________________________\n\n");
	printf("stack		A		B\n\n");
	while (i != 0)
	{
		printf("%d:", line);
		if (a)
		{
			printf("		%lld", a->content);
			a = a->next;
		}
		else
			printf("		");
		if (b)
		{
			printf("		%lld\n", b->content);
			b = b->next;
		}
		else
			printf("\n");
		i--;
		line++;
	}
	printf("__________________________________________\n\n");
	return ;
}

void	ft_push_swap(t_list **a, t_list **b)
{
	long long	i;

	i = (long long) ft_lstsize(*a);
	if (i == 2)
		ft_sort_for_two(a);
	else if (i == 3)
		ft_sort_for_thee(a);
	else if (i == 4)
		ft_sort_for_four(a, b, i);
	else if (i == 5)
		ft_sort_for_five(a, b, i);
	ft_view_the_stack(*a, *b); //the_magic_of_visualization
	//ft_lstclear_for_ps(a); //when you're done, don't forget to clear the list
	// ft_lstclear_for_ps(b); //when you're done, don't forget to clear the list
	ft_chek_on_sort(a);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		n;

	b = NULL;
	n = 1;
	if (argc == 2 && ft_strrchr_ps(argv[1], ' '))
	{
		argv = ft_split(argv[1], ' ');
		n = 0;
	}
	if (ft_pars(argv, n))
		return (0);
	if (argc < 2)
		return (0);
	ft_mk_lst(argv, &a, n);
	ft_view_the_stack(a, b); //the_magic_of_visualization
	if (ft_chek_on_sort(&a))
		ft_sort_done(&a);
	ft_push_swap(&a, &b);
	return (0);
}
