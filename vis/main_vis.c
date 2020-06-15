/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_vis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <btheia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 18:20:09 by btheia            #+#    #+#             */
/*   Updated: 2020/03/07 19:13:36 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual_header.h"

void	init_pos(t_vis *vis)
{
	vis->logo_pos.x = 150;
	vis->logo_pos.y = 0;
	vis->logo_pos.h = 200;
	vis->logo_pos.w = 900;
	vis->scor_pos.x = 60;
	vis->scor_pos.y = 305;
	vis->scor_pos.w = 200;
	vis->scor_pos.h = 200;
	vis->sub_pos.x = 900;
	vis->sub_pos.y = 260;
	vis->sub_pos.w = 300;
	vis->sub_pos.h = 300;
	vis->winner_pos.x = 500;
	vis->winner_pos.y = 200;
	vis->winner_pos.w = 200;
	vis->winner_pos.h = 100;
}

void	init_coord(t_vis *vis)
{
	vis->yellow.r = 247;
	vis->yellow.g = 250;
	vis->yellow.b = 0;
	vis->blue.r = 0;
	vis->blue.g = 60;
	vis->blue.b = 255;
	vis->name_pos1.x = 70;
	vis->name_pos1.y = 505;
	vis->name_pos1.h = 30;
	vis->name_pos1.w = 150;
	vis->name_pos2.x = 980;
	vis->name_pos2.y = 505;
	vis->name_pos2.h = 30;
	vis->name_pos2.w = 150;
}

void	init_name(t_vis *vis, char *name1, char *name2)
{
	SDL_Surface *surfacemessage;

	init_coord(vis);
	surfacemessage = TTF_RenderText_Solid(vis->font, name1, vis->yellow);
	(surfacemessage == NULL) ? exit(0) : 0;
	vis->name1 = SDL_CreateTextureFromSurface(vis->ren, surfacemessage);
	(vis->name1 == NULL) ? exit(0) : 0;
	SDL_FreeSurface(surfacemessage);
	surfacemessage = TTF_RenderText_Solid(vis->font, name2, vis->blue);
	(surfacemessage == NULL) ? exit(0) : 0;
	vis->name2 = SDL_CreateTextureFromSurface(vis->ren, surfacemessage);
	(vis->name2 == NULL) ? exit(0) : 0;
	SDL_FreeSurface(surfacemessage);
}

void	change_name(char *line)
{
	char	*help;
	int		k;

	if (line[0])
	{
		ft_memmove(ft_strstr(line, ".filler"), "\0", 1);
		help = ft_strrchr(line, '/');
		if (help && help + 1)
		{
			k = ft_strlen(help + 1);
			ft_memmove(line, help + 1, ft_strlen(help + 1));
			line[k] = 0;
		}
		if (!help)
		{
			k = ft_strlen(ft_strchr(line, '[') + 1);
			ft_memmove(line, ft_strchr(line, '[') + 1,
				ft_strlen(ft_strchr(line, '[') + 1));
			line[k] = 0;
		}
	}
}

int		main(void)
{
	t_vis	vis;
	int		l;
	char	buf[4097];

	vis.maps = NULL;
	if (!(vis.maps = (t_map *)malloc(sizeof(t_map))))
		return (0);
	ft_bzero(vis.maps->map, sizeof(int) * 10000);
	vis.maps->next = NULL;
	vis.maps->h = 0;
	vis.maps->w = 0;
	ft_bzero(vis.f, 100);
	ft_bzero(vis.s, 100);
	vis.map_c = 0;
	vis.s1 = -1;
	vis.s2 = -1;
	vis.speed = 500;
	vis.run = 1;
	parse_countmap(&vis);
	change_name(vis.f);
	change_name(vis.s);
	visual_f(&vis, vis.map_c);
	destroy_all(&vis);
	exit(0);
}
