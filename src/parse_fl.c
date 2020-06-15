/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <btheia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 20:15:11 by btheia            #+#    #+#             */
/*   Updated: 2020/03/06 19:26:50 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_header.h"

int		len_my(char *str)
{
	int	i;

	i = -1;
	while (!ft_isspace(str[++i]) && str[i])
	{
	}
	return (i);
}

int		check_string(t_game *game, char *line)
{
	int	res;

	res = 0;
	if (!game->c[0]++)
		(ft_strncmp("$$$", line, 3)) ? res++ : 0;
	else if (!game->c[1]++)
		(ft_strncmp("exec", line, 4)) ? res++ : 0;
	else if (!game->c[2]++)
	{
		if (ft_strncmp("p1", line, 2) && ft_strncmp("p2", line, 2))
			return (1);
		if (*(line + 1) == '1')
			game->c_b = 'O';
		else
			game->c_b = 'X';
	}
	else if (!game->c[3]++)
		(*line != ':') ? res++ : 0;
	else if (!game->c[4]++)
	{
		if ((*line != '[' || *(line + ft_strlen(line) - 1) != ']'))
			return (1);
	}
	return (res);
}

int		parse_num(t_game *game)
{
	char	*line;
	int		i;
	int		len;

	line = NULL;
	if ((gnl(0, &line)) == 0)
		del_str(line);
	i = 0;
	len = ft_strlen(line);
	while (i < len)
	{
		if (ft_isspace(line[i++]))
			continue;
		i--;
		if (check_string(game, &line[i]))
		{
			new_del(&line);
			return (1);
		}
		i += len_my(&line[i]);
	}
	free(line);
	return (!game->c[0] || !game->c[1]
	|| !game->c[2] || !game->c[3] || !game->c[4]);
}
