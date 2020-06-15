/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <btheia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 20:33:00 by btheia            #+#    #+#             */
/*   Updated: 2020/03/05 20:33:19 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_header.h"

void	new_del(char **line)
{
	if (*line)
	{
		free(*line);
		*line = NULL;
	}
}

void	print_map(int *arr, t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->h * game->w)
	{
		ft_printf("%+3d ", arr[i]);
		if (!((i + 1) % game->w))
			ft_printf("\n");
	}
}

void	print_piece(int *arr, t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->hp * game->wp)
	{
		ft_printf("%d", arr[i]);
		if (!((i + 1) % game->wp))
			ft_printf("\n");
	}
}

void	set_point(t_game *game, char *line, int *map, int numl)
{
	int	i;

	i = -1;
	while (++i < game->len_l - 4)
	{
		if (game->c_b == line[i] || game->c_s == line[i])
		{
			(game->im == -1) ? game->im = numl : 0;
			(game->jm == -1) ? game->jm = i : 0;
			game->im2 = numl;
			game->jm2 = i;
			map[i] = -1;
		}
		else if (game->p_b == line[i] || game->p_s == line[i])
		{
			(game->ip == -1) ? game->ip = numl : 0;
			(game->jp == -1) ? game->jp = i : 0;
			game->ip2 = numl;
			game->jp2 = i;
			map[i] = -2;
		}
		else
			map[i] = 0;
	}
}

void	set_point2(t_game *game, char *line, int *map, int numl)
{
	int	i;

	i = -1;
	while (++i < game->len_l)
	{
		if (line[i] == '*')
			map[i] = 1;
		else
			map[i] = 0;
	}
}
