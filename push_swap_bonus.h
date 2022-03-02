/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:30:55 by lcorinna          #+#    #+#             */
/*   Updated: 2022/03/02 19:07:41 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "push_swap.h"

void		ft_sort_done_bonus(t_list **lst, int flag);
void		ft_command_not_found(char **arr, int i, t_list **a, t_list **b);

void		ft_sa_bonus(t_list **a);
void		ft_sb_bonus(t_list **b);
void		ft_ss_bonus(t_list **a, t_list **b);
void		ft_pb_bonus(t_list **a, t_list **b);
void		ft_pa_bonus(t_list **a, t_list **b);

void		ft_ra_bonus(t_list **lst);
void		ft_rb_bonus(t_list **lst);
void		ft_rr_bonus(t_list **a, t_list **b);

void		ft_rra_bonus(t_list **lst);
void		ft_rrb_bonus(t_list **lst);
void		ft_rrr_bonus(t_list **a, t_list **b);

#endif
