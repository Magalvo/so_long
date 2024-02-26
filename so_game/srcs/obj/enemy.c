#include "../../headers/so_long.h"


void	update_enemy_sprite(t_img *img)
{
	img->curr_frame = (img->curr_frame + 1) % img->total_frames;
}

void	paint_enemy(t_vars *vars, t_img *img, int x, int y)
{
	int	frame_x_offset;
	int frame_y_offset;
	int	sy;
	int	sx;
	int	color;

	frame_x_offset = (img->curr_frame % img->total_frames) * WIDTH;
	frame_y_offset = vars->xdirection * HEIGHT;
	sy = 0;
	while (sy < HEIGHT)
	{
		sx= 0;
		while (sx < WIDTH)
		{
			color = my_mlx_pixel_get(img, frame_x_offset + sx, frame_y_offset + sy);
			my_mlx_pixel_put(&vars->canva, x + sx, y + sy, color);
			sx++;
		}
		sy++;
	}
}
static void	__render(t_object *this, t_vars *vars)
{
	if (this->move_counter++ >= this->move_interval)
	{
		this->move_counter = 0;
		if(!move_enemy(this, vars))
			enemy_dir(vars);
		printf("DIR: %d", vars->xdirection);
	}
	update_enemy_sprite(&this->imgs[0]);
	paint_enemy(vars, &this->imgs[0], this->x * 64, this->y * 64);
}
int	move_enemy(t_object *this, t_vars *vars)
{
	int	dx;
	int dy;
	int newX;
	int newY;

	dx = 0;
	dy = 0;
	if (vars->xdirection == D_UP)
		dy = -1;
	else if (vars->xdirection == D_RIGHT)
		dx = 1;
	else if (vars->xdirection == D_DOWN)
		dy = 1;
	else if (vars->xdirection == D_LEFT)
		dx = -1;
	newX = this->x + dx;
	newY = this->y + dy;
	if (vars->game.map[newY][newX] != '1' && vars->game.map[newY][newX] != 'C') 
	{ 
		this->x = newX;
		this->y = newY;
		return (1); 
	}
	return (0); 
}

t_object *new_enemy(t_vars *vars, int x, int y)
{
	t_object *enemy;

	enemy = ft_calloc(sizeof(t_object), 1);
	if (!enemy)
		exit_game(vars, "error on new player");
	vars->player = enemy;
	vars->xdirection = 0;
	enemy->x = x;
	enemy->y = y;
	enemy->render = __render;
	enemy->imgs = ft_calloc(sizeof(t_img),1);
	enemy->imgs[0] = load_img("img/Enemy/Lion4x4.xpm", vars);
	enemy->move_counter = 0;
	enemy->move_interval = 20;
	enemy->imgs->total_frames = 4;
	enemy->imgs->curr_frame = 0;
	enemy->imgs->curr_sprite = 0;
	printf("playerIn\n");
	return (enemy);
}