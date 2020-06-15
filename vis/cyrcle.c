/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cyrcle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <btheia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 01:48:31 by btheia            #+#    #+#             */
/*   Updated: 2020/03/07 18:31:12 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual_header.h"

void	set_point(char *line, int *map, int len_l)
{
	int	i;

	i = -1;
	while (++i < len_l - 4)
	{
		if (line[i] == 'O')
			map[i] = -1;
		else if (line[i] == 'o')
			map[i] = 1;
		else if (line[i] == 'X')
			map[i] = -2;
		else if (line[i] == 'x')
			map[i] = 2;
		else
			map[i] = 0;
	}
}

void	help_d(t_map *tmp, int w, int h)
{
	tmp->w = w;
	tmp->h = h;
	if (!(tmp->next = (t_map *)malloc(sizeof(t_map))))
		exit(0);
	tmp->next->next = NULL;
	ft_bzero(tmp->next->map, sizeof(int) * 10000);
	tmp->next->h = 0;
	tmp->next->w = 0;
}

void	new_map(t_vis *vis, char *line)
{
	int		h;
	int		w;
	int		loop;
	char	*l1;
	t_map	*tmp;

	tmp = get_last(vis);
	if (ft_strchr(line, ' ') != NULL)
	{
		h = ft_atoi(ft_strchr(line, ' ') + 1);
		if (ft_strchr(ft_strchr(line, ' ') + 1, ' ') != NULL)
			w = ft_atoi(ft_strchr(ft_strchr(line, ' ') + 1, ' '));
	}
	loop = -1;
	l1 = NULL;
	while (++loop < h)
	{
		if (gnl(0, &l1) != 0 && (ft_strlen(l1) == 4 + w)
					&& *(l1 + 3) == ' ')
			set_point(l1 + 4, tmp->map + loop * w, ft_strlen(l1));
		new_del(&l1);
	}
	help_d(tmp, w, h);
}

void	print_map(int *arr, t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->h * map->w)
	{
		ft_printf("%+3d ", arr[i]);
		if (!((i + 1) % map->w))
			ft_printf("\n");
	}
}

void	parse_countmap(t_vis *vis)
{
	char	*line;

	line = NULL;
	while (gnl(0, &line))
	{
		if (line[0] == '$')
		{
			if (!ft_strncmp("$$$ exec p1", line, 11))
				ft_memmove(vis->f, line, ft_strlen(line));
			else if (!ft_strncmp("$$$ exec p2", line, 11))
				ft_memmove(vis->s, line, ft_strlen(line));
		}
		else if (!ft_strncmp("Plateau", line, 7))
		{
			vis->map_c++;
			new_map(vis, line);
		}
		if (!ft_strncmp("== O", line, 4))
			vis->s1 = ft_atoi(ft_strrchr(line, ' ') + 1);
		if (!ft_strncmp("== X", line, 4))
			vis->s2 = ft_atoi(ft_strrchr(line, ' ') + 1);
		new_del(&line);
	}
	new_del(&line);
}
