/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 22:40:44 by lcorinna          #+#    #+#             */
/*   Updated: 2022/03/02 18:16:23 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef  BUFFER_SIZE
#  define  BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	long long		num;
	int				index;
	int				score;
	struct s_list	*next;
}	t_list;

void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char *s, char c);
size_t	ft_strlen(const char *r);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

size_t	ft_strlen_gnl(char *r);
char	*ft_strchr_gnl(char *s, int c);
char	*ft_substr_gnl(char *s, unsigned int start, size_t len);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_trim_for_str(char *res);
char	*ft_trim_for_res(char *res);
char	*ft_read(int fd, char *res, int *chit, int i);
char	*get_next_line(int fd);
char	*ft_res_res(char *res, int i);
char	*ft_free_res(char *res, int *chit);

#endif