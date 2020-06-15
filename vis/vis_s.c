/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vis_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <btheia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 03:44:52 by btheia            #+#    #+#             */
/*   Updated: 2020/03/07 19:21:03 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual_header.h"

void	send_fire(t_vis *vis, t_map *samp)
{
	SDL_Rect	p;
	int			i;

	p.x = 300;
	p.y = 300;
	p.h = 500 / (samp->h);
	p.w = 500 / (samp->w);
	i = -1;
	while (++i < samp->h * samp->w)
	{
		p.x = 300 + p.w * (i % samp->w);
		if (samp->map[i] == -1)
			SDL_RenderCopy(vis->ren, vis->fire, NULL, &p);
		else if (samp->map[i] == 1)
			SDL_RenderCopy(vis->ren, vis->bom, NULL, &p);
		else if (samp->map[i] == -2)
			SDL_RenderCopy(vis->ren, vis->ice, NULL, &p);
		else if (samp->map[i] == 2)
			SDL_RenderCopy(vis->ren, vis->snow, NULL, &p);
		else
			SDL_RenderCopy(vis->ren, vis->earth, NULL, &p);
		if (!((i + 1) % samp->w))
			p.y += p.h;
	}
}

void	winner(t_vis *vis, int len, SDL_Color col)
{
	char			l[len + 6];
	SDL_Surface		*surfacemessage;

	if (!vis->winner)
	{
		surfacemessage = NULL;
		ft_bzero(l, len + 6);
		if (vis->s1 > vis->s2)
			ft_memmove(l, vis->f, len);
		else
			ft_memmove(l, vis->s, len);
		ft_strcat(l, " won!");
		surfacemessage = TTF_RenderText_Solid(vis->font, l, col);
		(surfacemessage == NULL) ? exit(0) : 0;
		vis->winner = SDL_CreateTextureFromSurface(vis->ren, surfacemessage);
		SDL_FreeSurface(surfacemessage);
	}
	else
		SDL_RenderCopy(vis->ren, vis->winner, NULL, &vis->winner_pos);
}

void	help_f(t_vis *vis, int *i, SDL_Event e)
{
	if (e.type == SDL_QUIT)
		vis->run = 0;
	else if (e.key.keysym.sym == 1073741906)
		vis->speed = (vis->speed - 50 < 50) ? 50 : vis->speed - 50;
	else if (e.key.keysym.sym == 1073741905)
		vis->speed = (vis->speed + 50 > 2000) ? 2000 : vis->speed + 50;
	else if (e.key.keysym.sym == 27)
		vis->run = 0;
	else if (e.key.keysym.sym == 32)
		vis->pause = 0;
	else if (e.key.keysym.sym == 1073741903 && !vis->pause)
		(*i)++;
	else if (e.key.keysym.sym == 1073741904 && !vis->pause)
		(*i)--;
}

void	vis_init(t_vis *vis, int *i)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0 || TTF_Init() == -1)
		exit(1);
	init_vis(vis);
	init_text(vis);
	init_pos(vis);
	init_fire(vis);
	init_name(vis, vis->f, vis->s);
	*i = -1;
}

void	visual_f(t_vis *vis, int size)
{
	t_map		*list[size];
	SDL_Event	e;
	int			i;

	vis_init(vis, &i);
	in_mass(list, vis);
	while (vis->run)
	{
		while (SDL_PollEvent(&e) != 0)
		{
			help_f(vis, &i, e);
			break ;
		}
		SDL_RenderClear(vis->ren);
		(vis->pause) ? ++i : 0;
		if (i < size && i > 0)
			send_fire(vis, list[i]);
		else
		{
			send_fire(vis, list[size - 1]);
			(vis->s1 > vis->s2) ? (winner(vis, ft_strlen(vis->f), vis->yellow))
			: (winner(vis, ft_strlen(vis->s), vis->blue));
		}
		renders(vis);
	}
}
