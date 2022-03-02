/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:13:04 by lcorinna          #+#    #+#             */
/*   Updated: 2022/03/02 19:12:57 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_application_of_input_two(char **arr, int i, t_list **a, t_list **b)
{
	if (ft_strncmp(arr[i], "ra\n", 3) == 0)
		ft_ra_bonus(a);
	else if (ft_strncmp(arr[i], "rb\n", 3) == 0)
		ft_rb_bonus(b);
	else if (ft_strncmp(arr[i], "rr\n", 3) == 0)
		ft_rr_bonus(a, b);
	else if (ft_strncmp(arr[i], "rra\n", 3) == 0)
		ft_rra_bonus(a);
	else if (ft_strncmp(arr[i], "rrb\n", 3) == 0)
		ft_rrb_bonus(b);
	else if (ft_strncmp(arr[i], "rrr\n", 4) == 0)
		ft_rrr_bonus(a, b);
	else
		ft_command_not_found(arr, i, a, b);
	return (0);
}

int	ft_application_of_input(char **arr, int i, t_list **a, t_list **b)
{
	while (arr[i] != NULL)
	{
		if (arr[i][0] == 'r')
		{
			if (ft_application_of_input_two(arr, i, a, b))
				return (1);
		}
		else if (ft_strncmp(arr[i], "sa\n", 3) == 0)
			ft_sa_bonus(a);
		else if (ft_strncmp(arr[i], "sb\n", 3) == 0)
			ft_sb_bonus(b);
		else if (ft_strncmp(arr[i], "ss\n", 3) == 0)
			ft_ss_bonus(a, b);
		else if (ft_strncmp(arr[i], "pa\n", 3) == 0)
			ft_pa_bonus(a, b);
		else if (ft_strncmp(arr[i], "pb\n", 3) == 0)
			ft_pb_bonus(a, b);
		else
			ft_command_not_found(arr, i, a, b);
		i++;
	}
	return (0);
}

void	ft_sort_done_bonus(t_list **lst, int flag)
{
	ft_lstclear_for_ps(lst);
	if (flag == 1)
		write(1, "OK\n", 3);
	else if (flag == 2)
		write(1, "KO\n", 3);
	exit (0);
}

int	ft_commands(t_list **a, t_list **b)
{
	char	*arr[5500];
	int		flag;
	int		i;

	i = 0;
	flag = 0;
	while (flag != 1)
	{
		arr[i] = get_next_line(0);
		if (arr[i] == NULL)
			flag = 1;
		i++;
	}
	i = 0;
	ft_application_of_input(arr, i, a, b);
	while (arr[i])
		free(arr[i++]);
	if (*b != NULL)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		n;

	b = NULL;
	n = 1;
	if (argc < 2)
		return (0);
	if (argc == 2 && ft_strrchr_ps(argv[1], ' '))
	{
		argv = ft_split(argv[1], ' ');
		if (argv == NULL)
			return (0);
		n = 0;
	}
	argc = 0;
	ft_pars(argv, n, argc);
	ft_mk_lst(argv, &a, n);
	if (ft_commands(&a, &b))
		ft_sort_done_bonus(&a, 2);
	if (ft_chek_on_sort(&a))
		ft_sort_done_bonus(&a, 1);
	else
		ft_sort_done_bonus(&a, 2);
	return (0);
}
