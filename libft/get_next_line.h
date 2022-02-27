/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 19:26:30 by lcorinna          #+#    #+#             */
/*   Updated: 2022/02/27 19:34:04 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef  BUFFER_SIZE
#  define  BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>

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
