/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stune <stune@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 21:53:49 by stune             #+#    #+#             */
/*   Updated: 2021/01/12 18:54:22 by stune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int		get_next_line(int fd, char **line);
char	*ft_strchr_m(const char *s, int c);
size_t	ft_strlen_m(const char *str);
int		ft_output(char *buffer);
char	*ft_strjoin_m(char const *s1, char const *s2);
char	*ft_strdup_m(const char *s1);
int		ft_make_line(char **line, char **tail, char **buff);
int		ft_get_returm(int *re_by, char **tail, char **line, int i);
void	ft_if_tail(char **tail, char **line, int *i);

#endif
