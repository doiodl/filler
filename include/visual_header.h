/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_header.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <btheia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 21:53:27 by btheia            #+#    #+#             */
/*   Updated: 2020/03/07 18:57:57 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUAL_HEADER
# define VISUAL_HEADER
# include <SDL2/SDL.h>
# include <SDL2/SDL_ttf.h>
# include "ft_printf.h"
# define hw 1000
# define BUFF_SIZE 1000
typedef struct s_map
{
	int map[10000];
	int h;
	int w;
	struct s_map *next;
} t_map;

typedef struct		s_vis
{
	SDL_Window		*win;
	SDL_Renderer	*ren;
	SDL_Texture		*logo;
	SDL_Texture		*scor;
	SDL_Texture		*sub;
	SDL_Texture		*name1;
	SDL_Texture		*name2;
	SDL_Texture		*fire;
	SDL_Texture		*ice;
	SDL_Texture		*bom;
	SDL_Texture		*snow;
	SDL_Texture		*earth;
	SDL_Texture		*winner;
	SDL_Rect		logo_pos;
	SDL_Rect		scor_pos;
	SDL_Rect		sub_pos;
	SDL_Rect		name_pos1;
	SDL_Rect		name_pos2;
	SDL_Rect		winner_pos;
	SDL_Color		yellow;
	SDL_Color		blue;
	TTF_Font		*font;
	int				h;
	int				w;
	int				run;
	int				map_c;
	char			f[100];
	char			s[100];
	int				s1;
	int				s2;
	int				speed;
	t_map			*maps;
	int				pause;
}					t_vis;

void		parse_countmap(t_vis *vis);
int			gnl(const int fd, char **line);
void		print_map(int *arr, t_map *map);
void		init_vis(t_vis *vis);
void		init_text(t_vis *vis);
void		init_pos(t_vis *vis);
void		init_name(t_vis *vis, char *name1, char *name2);
void		visual_f(t_vis *vis, int size);
void		help_d(t_map *tmp, int w, int h);
void		new_del(char **line);
void		destroy_all(t_vis *vis);
void		in_mass(t_map **list, t_vis *vis);
void		init_fire(t_vis *vis);
void		renders(t_vis *vis);
t_map		*get_last(t_vis *vis);

#endif
