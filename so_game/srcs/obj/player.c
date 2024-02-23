/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:20:49 by dde-maga          #+#    #+#             */
/*   Updated: 2024/02/23 17:16:41 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"


void	update_player_sprite(t_img *img)
{
	img->curr_frame = (img->curr_frame + 1) % img->total_frames;
}

void	paint_player(t_vars *vars, t_img *img, int x, int y)
{
	int	frame_x_offset;
	int frame_y_offset;
	int	sy;
	int	sx;
	int	color;

	frame_x_offset = (img->curr_frame % img->total_frames) * WIDTH;
	frame_y_offset = vars->pdirection * HEIGHT;
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
	update_player_sprite(&this->imgs[0]);
	paint_player(vars, &this->imgs[0], this->x * 64, this->y * 64);
}

int	move_player(t_object *this, int sx, int sy, t_vars *vars)
{
	int	x;
	int	y;

	x = this->x + sx;
	y = this->y + sy;

	printf("x: %i y: %i\n", sx, sy);
	if (vars->game.map[y][x] == '1')
		return (0);
	if (vars->game.map[y][x] == 'X')
		exit_game(vars, "Your where slained by the farmer!");
	printf("mx: %i my: %i\n", x, y);
	this->x = x;
	this->y = y;
	return (1);
}

t_object *new_player(t_vars *vars, int x, int y)
{
	t_object *player;

	player = ft_calloc(sizeof(t_object), 1);
	if (!player)
		exit_game(vars, "error on new player");
	vars->player = player;
	vars->pdirection = 0;
	player->x = x;
	player->y = y;
	player->render = __render;
	player->imgs = ft_calloc(sizeof(t_img),1);
	player->imgs[0] = load_img("img/Player/FoxAll.xpm", vars);
	player->imgs->total_frames = 3;
	player->imgs->curr_frame = 0;
	player->imgs->curr_sprite = 0;
	printf("playerIn\n");
	return (player);
}



