/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <btheia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 20:07:22 by btheia            #+#    #+#             */
/*   Updated: 2020/03/06 19:24:15 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_header.h"

void	del_str(char *line)
{
	ft_printf("ERROR\n");
}

int		check_per(int d, char *line, char *cl)
{
	char *c;

	if (!(c = ft_itoa(d)))
		del_str(line);
	if (ft_strchr(cl, ' '))
	{
		if (ft_strncmp(c, cl, ft_strchr(cl, ' ') - cl))
		{
			c ? free(c) : 0;
			return (-1);
		}
	}
	else
	{
		if (ft_strncmp(c, cl, ft_strlen(c)))
		{
			c ? free(c) : 0;
			return (-1);
		}
	}
	c ? free(c) : 0;
	return (d);
}

int		parse_platue(t_game *game)
{
	char	*line;
	int		k;

	line = NULL;
	k = 0;
	if (gnl(0, &line) != 0)
	{
		if (!ft_strncmp("Plateau", line, 7) && ft_strchr(line, ':'))
		{
			if (ft_strchr(line, ' ') != NULL)
			{
				game->h = ft_atoi(ft_strchr(line, ' ') + 1);
				game->h = check_per(game->h, line, ft_strchr(line, ' ') + 1);
				if (ft_strchr(ft_strchr(line, ' ') + 1, ' ') != NULL)
				{
					game->w = ft_atoi(ft_strchr(ft_strchr(line, ' ') + 1, ' '));
					game->w = check_per(game->w, line,
					ft_strchr(ft_strchr(line, ' ') + 1, ' '));
				}
			}
			k++;
		}
	}
	new_del(&line);
	return (k);
}

void	help_in(t_game *game, int k)
{
	if (k)
	{
		game->w = -1;
		game->ip = -1;
		game->jp = -1;
		game->hp = -1;
		game->wp = -1;
		game->im = -1;
		game->jm = -1;
		game->res = 0;
		game->end = 1;
		return ;
	}
	if (game->c_b == 'X')
	{
		game->c_s = 'x';
		game->p_b = 'O';
		game->p_s = 'o';
	}
	else
	{
		game->c_s = 'o';
		game->p_b = 'X';
		game->p_s = 'x';
	}
}

int		main(void)
{
	t_game	game;

	ft_bzero(game.c, sizeof(int) * 5);
	if (parse_num(&game) != 0)
	{
		ft_printf("Bad player info\n");
		exit(0);
	}
	help_in(&game, 0);
	while (1)
	{
		help_in(&game, 1);
		game.h = -1;
		if (parse_platue(&game) && game.h != -1 && game.w != -1)
			alg(&game, game.h * game.w);
		if (game.end)
			return (0);
	}
	return (0);
}
