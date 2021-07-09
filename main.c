/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stune <stune@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 18:49:26 by stune             #+#    #+#             */
/*   Updated: 2021/03/30 18:44:29 by stune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		main(int argc, char *argv[])
{
	int		fd;
	char	*line;
	t_list	*l_map;
	t_elem	*elem;

	line = NULL;
	l_map = NULL;
	if (0 > (fd = open(argv[1], O_RDONLY)))
		print_error(2);
	while (get_next_line(fd, &line) && fd != -1)
		ft_lstadd_back(&l_map, ft_lstnew(line));
	if (fd > 2)
		close(fd);
	ft_lstadd_back(&l_map, ft_lstnew(line));
	elem = ft_type_elem(l_map);
	arg_comang_shell(argc, argv, elem);
	g_win_test(elem);
	free_all_struct(elem, l_map);
}

void	arg_comang_shell(int argc, char **argv, t_elem *elem)
{
	if (argc == 3 && (ft_strncmp(argv[2], "--save", 6) == 0))
		elem->screen = 1;
	else
		elem->screen = 0;
	if (argc == 1)
		write(1, "No map file\n", 12);
	else if (!ft_strnstr(argv[1], ".cub", ft_strlen(argv[1])))
	{
		write(2, "Wrong format\n", 13);
		exit(0);
	}
}

void	free_all_struct(t_elem *elem, t_list *l_map)
{
	int	i;

	i = 0;
	ft_lstclear(&l_map, free);
	while (elem->map[i])
	{
		free(elem->map[i]);
		i++;
	}
	free(elem->map);
	free(elem->all_color);
	free(elem);
}
