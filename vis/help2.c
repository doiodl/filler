/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <btheia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 18:49:12 by btheia            #+#    #+#             */
/*   Updated: 2020/03/07 19:12:33 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual_header.h"

void	renders(t_vis *vis)
{
	SDL_RenderCopy(vis->ren, vis->logo, NULL, &vis->logo_pos);
	SDL_RenderCopy(vis->ren, vis->sub, NULL, &vis->sub_pos);
	SDL_RenderCopy(vis->ren, vis->scor, NULL, &vis->scor_pos);
	SDL_RenderCopy(vis->ren, vis->name1, NULL, &vis->name_pos1);
	SDL_RenderCopy(vis->ren, vis->name2, NULL, &vis->name_pos2);
	SDL_RenderPresent(vis->ren);
	SDL_Delay(vis->speed);
}

void	init_fire(t_vis *vis)
{
	SDL_Surface *bmp;

	bmp = SDL_LoadBMP("./vis/photo/fire.bmp");
	(bmp == NULL) ? exit(0) : 0;
	vis->fire = SDL_CreateTextureFromSurface(vis->ren, bmp);
	SDL_FreeSurface(bmp);
	bmp = SDL_LoadBMP("./vis/photo/ice.bmp");
	(bmp == NULL) ? exit(0) : 0;
	vis->ice = SDL_CreateTextureFromSurface(vis->ren, bmp);
	SDL_FreeSurface(bmp);
	bmp = SDL_LoadBMP("./vis/photo/bom.bmp");
	(bmp == NULL) ? exit(0) : 0;
	vis->bom = SDL_CreateTextureFromSurface(vis->ren, bmp);
	SDL_FreeSurface(bmp);
	bmp = SDL_LoadBMP("./vis/photo/snow.bmp");
	(bmp == NULL) ? exit(0) : 0;
	vis->snow = SDL_CreateTextureFromSurface(vis->ren, bmp);
	SDL_FreeSurface(bmp);
	bmp = SDL_LoadBMP("./vis/photo/earth.bmp");
	(bmp == NULL) ? exit(0) : 0;
	vis->earth = SDL_CreateTextureFromSurface(vis->ren, bmp);
	SDL_FreeSurface(bmp);
	vis->winner = NULL;
}

void	destroy_all(t_vis *vis)
{
	SDL_DestroyTexture(vis->logo);
	SDL_DestroyTexture(vis->scor);
	SDL_DestroyTexture(vis->sub);
	SDL_DestroyTexture(vis->name1);
	SDL_DestroyTexture(vis->name2);
	SDL_DestroyTexture(vis->fire);
	SDL_DestroyTexture(vis->ice);
	SDL_DestroyTexture(vis->bom);
	SDL_DestroyTexture(vis->snow);
	SDL_DestroyTexture(vis->earth);
	SDL_DestroyTexture(vis->winner);
	SDL_DestroyRenderer(vis->ren);
	SDL_DestroyWindow(vis->win);
	SDL_Quit();
}

void	in_mass(t_map **list, t_vis *vis)
{
	t_map	*tmp;
	int		i;

	i = 0;
	tmp = vis->maps;
	while (tmp)
	{
		list[i++] = tmp;
		tmp = tmp->next;
	}
}
