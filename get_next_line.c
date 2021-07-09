/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stune <stune@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 21:53:27 by stune             #+#    #+#             */
/*   Updated: 2021/01/12 18:52:57 by stune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_make_line(char **line, char **tail, char **buff)
{
	int		i;
	char	*tmp;

	i = 1;
	tmp = *line;
	if (!(*line = ft_strjoin_m(tmp, *buff)))
		i = -1;
	free(tmp);
	*tail = ft_strchr_m(*line, '\n');
	if (*tail)
	{
		**tail = '\0';
		(*tail)++;
		if (!(*tail = ft_strdup_m(*tail)))
			i = -1;
	}
	return (i);
}

void	ft_if_tail(char **tail, char **line, int *i)
{
	char	*tmp;

	if (tail)
	{
		tmp = *line;
		if (!(*line = ft_strjoin_m(tmp, *tail)))
			*i = -1;
		free(*tail);
		free(tmp);
		*tail = NULL;
	}
}

int		ft_get_returm(int *re_by, char **tail, char **line, int i)
{
	if (!*re_by && !*tail)
		i = 0;
	if (*line == NULL)
	{
		if (!(*line = ft_strdup_m("\0")))
			return (-1);
	}
	if (*re_by == -1 || i == -1)
		return (-1);
	if (i)
		return (1);
	else
		return (0);
}

int		get_next_line(int fd, char **line)
{
	static char *tail;
	int			re_by;
	char		*buff;
	int			i;
	char		*tmp;

	i = 0;
	if (!(buff = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1)))
	|| fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	*line = NULL;
	ft_if_tail(&tail, line, &i);
	while ((!tail && (re_by = read(fd, buff, BUFFER_SIZE)) && re_by != -1)
	&& re_by != -1 && i != -1)
	{
		buff[re_by] = '\0';
		i = ft_make_line(line, &tail, &buff);
	}
	if (!re_by && *line && **line != '\0')
	{
		tmp = NULL;
		i = ft_make_line(line, &tail, &tmp);
	}
	free(buff);
	return (ft_get_returm(&re_by, &tail, line, i));
}
