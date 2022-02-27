/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:13:04 by lcorinna          #+#    #+#             */
/*   Updated: 2022/02/27 19:38:06 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		n;
	int		counter;

	counter = 0;
	b = NULL;
	n = 1;
	if (argc == 2 && ft_strrchr_ps(argv[1], ' '))
	{
		argv = ft_split(argv[1], ' ');
		if (argv == NULL)
			return (0);
		n = 0;
	}
	ft_pars(argv, n, counter);
	if (argc < 2)
		return (0);
	ft_mk_lst(argv, &a, n);
	ft_view_the_stack(a, b); //the_magic_of_visualization
	if (ft_chek_on_sort(&a))
		ft_sort_done(&a);
	return (0);
}

// ft_view_the_stack(a, b); //the_magic_of_visualization

void	ft_view_the_stack(t_list *a, t_list *b)
{
	int	line;
	int	i;
	int	j;

	i = ft_lstsize(a);
	j = ft_lstsize(b);
	if (j > i)
		i = j;
	line = 1;
	printf("_____________________________________________________________\n\n");
	printf("stack		A	index	score		B	index	score\n\n");
	while (i != 0)
	{
		printf("%d:", line);
		if (a)
		{
			printf("		%lld", a->num);
			printf("	%d", a->index);
			printf("	%d", a->score);
			a = a->next;
		}
		else
			printf("				");
		if (b)
		{
			printf("		%lld", b->num);
			printf("	%d", b->index);
			printf("	%d\n", b->score);
			b = b->next;
		}
		else
			printf("\n");
		i--;
		line++;
	}
	printf("_____________________________________________________________\n\n");
	return ;
}