#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "minilibx-linux/mlx.h"
#include <X11/keysym.h>
#include <X11/X.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>


typedef struct s_img
{
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
    char    *relative_path;
    int     curr_sprite;
    int     tamsprite;
    int     img_width;
    int     img_height;
    int     curr_sx;
    int     curr_sy;
    int     prev_sx;
    int     prev_sy;
    int     total_frames;
    int     curr_frame;
    }  t_img;





typedef struct  s_vars {
    void    *mlx;
    void    *win;
    int     keypress;
    int     keycode;
    int     action;
    t_img   *person;
    t_img   img;
    t_img   canva;
    t_img   walls;
}               t_vars;



void my_mlx_pixel_put(t_img *data, int x, int y, int color);
int my_mlx_pixel_get(t_img *data, int x, int y);
t_img load_img(char *path, t_vars *varg);
void loadallimg(t_vars *vars);

//void paint_canvaw(t_vars *varg, t_img *img, float w, float h);
void    paintcanva(t_vars *varg, t_img *img, int sx, int sy);
void    paint_canvaw(t_vars *varg, t_img *img);