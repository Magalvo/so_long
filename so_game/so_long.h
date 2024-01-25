#include "minilibx-linux/mlx.h"
#include <X11/X.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/keysym.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef SO_LONG_H
# define SO_LONG_H
typedef struct s_img
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
}			t_img;

typedef struct s_map {
	int		width;
	int		height;
	char	**map;
	char	**cpymap;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	int		enemy_x;
	int		enemy_y;
	int		collectibles;
	int		collectibles_found;
	int		exit_found;
} t_map;

typedef struct s_assets {
    t_img img;            // Image data, likely including a pointer to the image and other properties.
    char *relative_path;  // The file path relative to the program's directory, used to load the image.
    int img_width;        // The width of the image.
    int img_height;       // The height of the image.
} t_assets;


typedef struct s_vars
{
	void	*mlx;
	void	*win;
	int		keypress;
	int		keycode;
	int		action;
	int		move_x;
	int		move_y;
	t_map	game;
	t_img	*person;
	t_img	img;
	t_img	canva;
	t_img	walls;
}			t_vars;

void		my_mlx_pixel_put(t_img *data, int x, int y, int color);
int			my_mlx_pixel_get(t_img *data, int x, int y);
t_img		load_img(char *path, t_vars *varg);

//void paint_canvaw(t_vars *varg, t_img *img, float w, float h);
void		paintcanva(t_vars *varg, t_img *img, int sx, int sy);
void		paint_canvaw(t_vars *varg, t_img *img);
int			name_check(char *pathname);
int			mapping(char *map, t_map *smap);
int			validate_map(t_map *smap);
void		*ft_realloc(void *ptr, size_t old_size, size_t new_size);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		loadallimg(t_vars *vars);
void		update_sprite(t_img *img);
int			animation_loop(t_vars *varg);
int			draw_borders(t_map smapi, t_vars *vars);
int			draw_window(t_map smapi, t_vars *vars);
int			ft_strlen(const char *str);
void		read_map_lines(int fd, t_map *smap, int *ln_ctd);
#endif
