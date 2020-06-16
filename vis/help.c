/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 18:25:14 by btheia            #+#    #+#             */
/*   Updated: 2020/06/16 23:41:37 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual_header.h"

void	init_vis(t_vis *vis)
{
	vis->win = NULL;
	vis->logo = NULL;
	vis->scor = NULL;
	vis->sub = NULL;
	vis->ren = NULL;
	vis->font = NULL;
	vis->run = 1;
	vis->pause = 1;
	vis->font = TTF_OpenFont("./vis/photo/mk2.ttf", 24);
	(vis->font == NULL) ? exit(0) : 0;
}

void	init_text(t_vis *vis)
{
	SDL_Surface *bmp;

	bmp = NULL;
	vis->win = SDL_CreateWindow("FILLER by btheia!",
		100, 100, 1200, 800, SDL_WINDOW_SHOWN);
	(vis->win == NULL) ? exit(0) : 0;
	vis->ren = SDL_CreateRenderer(vis->win, -1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	(vis->ren == NULL) ? exit(0) : 0;
	bmp = SDL_LoadBMP("./vis/photo/logo.bmp");
	(bmp == NULL) ? exit(0) : 0;
	vis->logo = SDL_CreateTextureFromSurface(vis->ren, bmp);
	SDL_FreeSurface(bmp);
	(vis->logo == NULL) ? exit(0) : 0;
	bmp = SDL_LoadBMP("./vis/photo/scor1.bmp");
	(bmp == NULL) ? exit(0) : 0;
	vis->scor = SDL_CreateTextureFromSurface(vis->ren, bmp);
	SDL_FreeSurface(bmp);
	(vis->scor == NULL) ? exit(0) : 0;
	bmp = SDL_LoadBMP("./vis/photo/sub1.bmp");
	(bmp == NULL) ? exit(0) : 0;
	vis->sub = SDL_CreateTextureFromSurface(vis->ren, bmp);
	SDL_FreeSurface(bmp);
	(vis->sub == NULL) ? exit(0) : 0;
}

void	new_del(char **line)
{
	if (*line)
	{
		free(*line);
		*line = NULL;
	}
}

t_map	*get_last(t_vis *vis)
{
	t_map *tmp;

	tmp = vis->maps;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}
