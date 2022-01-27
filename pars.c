/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:54:48 by lcorinna          #+#    #+#             */
/*   Updated: 2022/01/27 18:08:31 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ft_number(char *done)
{
	long long	res;
	int			i;

	i = 0;
	res = 0;
	while (done[i] > 47 && done[i] < 58)
	{
		res = res * 10 + (done[i] - 48);
		i++;
	}
	return (res);
}

long long	ft_atoi_for_ps(char *s)
{
	long long	res;
	int			i;
	int			j;

	res = 0;
	i = 0;
	while ((s[i] == 32) || (s[i] > 8 && s[i] < 14))
		i++;
	j = i;
	while (s[j])
	{
		if (s[j] == 45 || s[j] == 43)
			j++;
		if (s[j] < '0' || s[j++] > '9')
			return (2147483648);
	}
	if (s[i] == 45)
		res = (ft_number((char *) &s[++i]) * (-1));
	else if (s[i] == 43)
		res = (ft_number((char *) &s[++i]));
	else
		res = (ft_number((char *) &s[i]));
	if (res > 2147483647 || res < -2147483648)
		return (2147483648);
	return (res);
}

int	ft_pars(char **argv, int n)
{
	int		j;
	int		i;

	while (argv[n])
	{
		if ((ft_atoi_for_ps(argv[n++])) > 2147483647)
			ft_input_error("Error\n", 2);
	}
	n = 0;
	while (argv[n + 1])
	{
		j = -1;
		i = -1;
		while (argv[n][++i] == argv[n + 1][++j])
		{
			if (argv[n][i] == '\0' && argv[n + 1][j] == '\0')
				ft_input_error("Error\n", 2);
		}
		n++;
	}
	return (0);
}
