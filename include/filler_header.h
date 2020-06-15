#ifndef FILLER_HEADER
# define FILLER_HEADER
# define BUFF_SIZE 10000
# include "ft_printf.h"

typedef struct	s_game
{
    char        c_b;
    char        c_s;
    char		p_b;
	char 		p_s;
	int			c[5];
	int			w;
	int			h;
	int			im;
	int			jm;
	int			im2;
	int			jm2;
	int			ip;
	int			jp;
	int			ip2;
	int			jp2;
	int			len_l;
	int			wp;
	int			hp;
	int			pai;
	int			paj;
	int			res;
	int			end;
}				t_game;

void	alg3(t_game *game, int *map, int size);
int		get_d(int i, int j, int x, int y);
void	hh_2(t_game *game, int c, int k, int *d);
void	alg2(t_game *game, int *map);
void	alg(t_game *game, int size);
void	new_del(char **line);
void	print_map(int *arr, t_game *game);
void	print_piece(int *arr, t_game *game);
void	set_point(t_game *game, char *line, int *map, int numl);
void	set_point2(t_game *game, char *line, int *map, int numl);
int		check_piece(t_game *game, char *line);
int		alg5(t_game *game, int *map, int *piece);
void	help_alg4(t_game *game, int res, int i, int j);
void	init_i(t_game *game, int *i, int *imax);
void	alg4(t_game *game, int *map, int *piece);
int		gnl(const int fd, char **line);
void	del_str(char *line);
int		check_per(int d, char *line, char *cl);
int		parse_platue(t_game *game);
void	help_in(t_game *game, int k);
int		len_my(char *str);
int		check_string(t_game *game, char *line);
int		parse_num(t_game *game);
int		check_per(int d, char *line, char *cl);
void	del_str(char *line);

#endif
