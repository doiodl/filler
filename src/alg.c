/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <btheia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 20:21:13 by btheia            #+#    #+#             */
/*   Updated: 2020/03/05 20:33:11 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_header.h"

void	alg3(t_game *game, int *map, int size)
{
	char	*line;
	int		loop;
	int		piece[size];

	line = NULL;
	loop = -1;
	ft_bzero(piece, sizeof(int) * size);
	while (++loop < game->hp)
	{
		if (gnl(0, &line) != 0 && (game->len_l = ft_strlen(line)) == game->wp)
			set_point2(game, line, piece + loop * game->wp, loop);
		new_del(&line);
	}
	alg4(game, map, piece);
}

int		get_d(int i, int j, int x, int y)
{
	return (abs(i - x) + abs(j - y));
}

void	hh_2(t_game *game, int c, int k, int *d)
{
	if (*d == 0)
		*d = get_d(c / game->w, c % game->w, k / game->w, k % game->w);
	else if (get_d(c / game->w, c % game->w, k / game->w, k % game->w) <= *d)
		*d = get_d(c / game->w, c % game->w, k / game->w, k % game->w);
}

void	alg2(t_game *game, int *map)
{
	int c;
	int d;
	int	k;

	c = -1;
	while (++c < game->h * game->w)
	{
		if (map[c] == 0)
		{
			d = 0;
			k = game->ip * game->w + game->jp - 1;
			while (++k <= game->ip2 * game->w + game->jp2)
			{
				if (map[k] == -2)
					hh_2(game, c, k, &d);
			}
			map[c] = d;
		}
	}
}

void	alg(t_game *game, int size)
{
	char	*line;
	int		map[size];
	int		loop;

	line = NULL;
	ft_bzero(map, sizeof(int) * size);
	loop = -1;
	if (gnl(0, &line) != 0)
	{
		new_del(&line);
		while (++loop < game->h)
		{
			if (gnl(0, &line) != 0 &&
				(game->len_l = ft_strlen(line)) == 4 + game->w
					&& *(line + 3) == ' ')
				set_point(game, line + 4, map + loop * game->w, loop);
			new_del(&line);
		}
		alg2(game, map);
		if (gnl(0, &line) != 0)
			if (check_piece(game, line) && game->hp != -1 && game->wp != -1)
				alg3(game, map, game->wp * game->hp);
		new_del(&line);
	}
	new_del(&line);
}
