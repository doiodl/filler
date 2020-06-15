/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <btheia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 20:32:46 by btheia            #+#    #+#             */
/*   Updated: 2020/03/05 20:58:33 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_header.h"

int		check_piece(t_game *game, char *line)
{
	if (!ft_strncmp("Piece", line, 5) && ft_strchr(line, ':'))
	{
		if (ft_strchr(line, ' ') != NULL)
		{
			game->hp = ft_atoi(ft_strchr(line, ' ') + 1);
			game->hp = check_per(game->hp, line, ft_strchr(line, ' ') + 1);
			if (ft_strchr(ft_strchr(line, ' ') + 1, ' ') != NULL)
			{
				game->wp = ft_atoi(ft_strchr(ft_strchr(line, ' ') + 1, ' '));
				game->wp = check_per(game->wp, line,
				ft_strchr(ft_strchr(line, ' ') + 1, ' '));
			}
		}
		return (1);
	}
	return (0);
}

int		alg5(t_game *game, int *map, int *piece)
{
	int	i;
	int	j;
	int nc;
	int	res_n;

	nc = 0;
	res_n = 0;
	i = -1;
	while (++i < game->hp)
	{
		j = -1;
		while (++j < game->wp)
		{
			if (map[i * game->w + j] == -2)
				return (-1);
			if (map[i * game->w + j] == -1 && piece[i * game->wp + j] == 1)
				nc++;
			if (nc > 1)
				return (-1);
			if (map[i * game->w + j] > 0)
				res_n += map[i * game->w + j] * piece[i * game->wp + j];
		}
	}
	return ((nc == 0) ? (-1) : res_n);
}

void	help_alg4(t_game *game, int res, int i, int j)
{
	if (game->res == 0 && res != -1)
	{
		game->pai = i;
		game->paj = j;
		game->res = res;
		game->end = 0;
	}
	else if (game->res > res && res != -1)
	{
		game->pai = i;
		game->paj = j;
		game->res = res;
	}
}

void	init_i(t_game *game, int *i, int *imax)
{
	*i = (game->im - game->hp + 1 < 0) ? -1 : (game->im - game->hp);
	*imax = (game->im2 + game->hp > game->h) ?
		(game->h - game->hp + 1) : (game->im2 + 1);
}

void	alg4(t_game *game, int *map, int *piece)
{
	int		i;
	int		j;
	int		imax;
	int		jmax;
	int		res;

	game->pai = 0;
	game->paj = 0;
	if (game->wp < game->w && game->hp < game->h)
	{
		init_i(game, &i, &imax);
		while (++i < imax)
		{
			j = -1;
			while (++j < game->w)
			{
				if (j + game->wp > game->w)
					continue;
				res = alg5(game, map + i * game->w + j, piece);
				help_alg4(game, res, i, j);
			}
		}
	}
	ft_printf("%d %d\n", game->pai, game->paj);
}
