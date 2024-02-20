/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:23:32 by dde-maga          #+#    #+#             */
/*   Updated: 2024/02/20 11:19:14 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "macros.h"

typedef struct	s_object	t_object;
typedef struct	s_map		t_map;
typedef struct	s_img		t_img;
typedef struct	s_vars		t_vars;

struct	s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	char	*relative_path;
	int		curr_sprite;
	int		tamsprite;
	int		img_width;
	int		img_height;
	int		curr_sx;
	int		curr_sy;
	int		prev_sx;
	int		prev_sy;
	int		total_frames;
	int		curr_frame;
};

struct	s_object
{
	int			x;
	int			y;
	t_img		*imgs;
	void		(*render)(t_object *this, t_vars *vars);
	t_object	*next;
};

struct	s_map
{
	int		width;
	int		height;
	char	**map;
	char	**cpymap;
	int		collectibles_count; //All colectibles
	int		collectibles_found; //Nuber of flood fill colectibles
	int		exit_x;
	int		exit_y;
	int		exit_found;
	int		player_x;
	int		player_y;
	int		sx[2];
	int		sy[2];
};


struct	s_vars
{
	void		*mlx;
	void		*win;
	t_object 	*objects;
	t_object 	*player;
	t_map		game;
	t_img		canva;
};





void		my_mlx_pixel_put(t_img *data, int x, int y, int color);
int			my_mlx_pixel_get(t_img *data, int x, int y);
t_img		load_img(char *path, t_vars *varg);

//void paint_canvaw(t_vars *varg, t_img *img, float w, float h);
void		paintcanva(t_vars *varg, t_img *img, int sx, int sy);
void		paint_canvaw(t_vars *varg, t_img *img);
int			name_check(t_vars *vars, char *pathname);
int			mapping(t_vars *vars, char *map);
int			validate_map(t_vars *vars, t_map *smap);
void		update_sprite(t_img *img);
int			animation_loop(t_vars *varg);
int			draw_borders(t_map smapi, t_vars *vars);
int			draw_window(t_map smapi, t_vars *vars);
void		flood_fill(t_vars *vars, int sx, int sy, t_map *smap);
void		ft_print_fill(t_map *smap);
t_object	*create_object(int x, int y, t_img *imgs, void (*render)(t_object *));
void		append_object(t_object **list, t_object *new_obj);

int 		exit_game(t_vars *vars, char *msg);
void 		free_map(t_map *smap);


#endif
