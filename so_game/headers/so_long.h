/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:23:32 by dde-maga          #+#    #+#             */
/*   Updated: 2024/02/27 17:34:25 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "macros.h"

typedef struct s_object	t_object;
typedef struct s_map	t_map;
typedef struct s_img	t_img;
typedef struct s_vars	t_vars;
typedef struct s_val	t_val;

struct					s_img
{
	void				*img;
	char				*addr;
	char				*relative_path;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
	int					curr_sprite;
	int					tamsprite;
	int					img_width;
	int					img_height;
	int					curr_sx;
	int					curr_sy;
	int					prev_sx;
	int					prev_sy;
	int					total_frames;
	int					curr_frame;
};

struct					s_object
{
	void				(*render)(t_object *this, t_vars *vars);
	int					x;
	int					y;
	int					move_counter;
	int					move_interval;
	int					moves;
	int					collected;
	t_img				*imgs;
	t_object			*next;
};

struct					s_map
{
	int					width;
	int					height;
	int					collectibles_count;
	int					objects_count;
	int					exit_found;
	int					counter;
	char				**map;
	char				**cpymap;
};

struct					s_val
{
	int					players;
	int					exits;
	int					collectibles;
	int					sx;
	int					sy;
};

struct					s_vars
{
	void				*mlx;
	void				*win;
	int					pdirection;
	int					xdirection;
	t_object			*objects;
	t_object			*enemy;
	t_object			*player;
	t_map				game;
	t_img				canva;
	t_img				wall;
	t_img				floor;
	t_img				exit;
	t_val				val;
};

//===================MY_MLX===================//
void					my_mlx_pixel_put(t_img *data, int x, int y, int color);
int						my_mlx_pixel_get(t_img *data, int x, int y);

//===================CHECKERS===================//
void					flood_fill(t_vars *vars, int sx, int sy, t_map *smap);
void					create_object_all(t_map smapi, t_vars *vars);
int						name_check(t_vars *vars, char *pathname);
int						mapping(t_vars *vars, char *map);
int						validate_map(t_vars *vars, t_map *smap);

//===================DRAW======================//
void					paintcanva(t_vars *varg, t_img *img, int sx, int sy);
void					paint_canvaw(t_vars *varg, t_img *img, int sx, int sy);
void					update_sprite(t_img *img);
void					collect_item(t_vars *vars, int x, int y);
void					enemy_dir(t_vars *vars);
void					display_counter(t_vars *vars, int x, int y, int number);
int						draw_map(t_vars *vars);
int						init_window(t_map smapi, t_vars *vars);
int						move_player(t_object *this, int sx, int sy,
							t_vars *vars);
int						move_enemy(t_object *this, t_vars *vars);
bool					check_time(long long *last_time);
t_img					load_img(char *path, t_vars *varg);

//===================CLEANING===================//
void					free_map(t_map *smap);
void					free_objects(t_object *objects, t_vars *vars);
int						exit_game(t_vars *vars, char *msg);
int						close_window(t_vars *vars);

//===================OBJECTS===================//
t_object				*new_player(t_vars *vars, int x, int y);
t_object				*new_collectible(t_vars *vars, int x, int y);
t_object				*new_exit(t_vars *vars, int x, int y);
t_object				*new_enemy(t_vars *vars, int x, int y);

#endif
