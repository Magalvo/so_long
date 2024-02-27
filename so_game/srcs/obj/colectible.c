/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colectible.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:20:43 by dde-maga          #+#    #+#             */
/*   Updated: 2024/02/27 17:30:09 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

void	update_chicken_sprite(t_img *img)
{
	img->curr_frame = (img->curr_frame + 1) % img->total_frames;
}

void	paint_chicken(t_vars *vars, t_img *img, int x, int y)
{
	int	frame_x_offset;
	int	frame_y_offset;
	int	sy;
	int	sx;
	int	color;

	frame_x_offset = (img->curr_frame % img->total_frames) * WIDTH;
	frame_y_offset = HEIGHT;
	sy = 0;
	while (sy < HEIGHT)
	{
		sx = 0;
		while (sx < WIDTH)
		{
			color = my_mlx_pixel_get(img, frame_x_offset + sx, sy);
			my_mlx_pixel_put(&vars->canva, x + sx, y + sy, color);
			sx++;
		}
		sy++;
	}
}

static void	__render(t_object *this, t_vars *vars)
{
	if (vars->player->x == this->x && vars->player->y == this->y
		&& !this->collected)
	{
		ft_printf("YUM! Delicious\n");
		collect_item(vars, this->x, this->y);
	}
	if (!this->collected)
	{
		update_chicken_sprite(&this->imgs[0]);
		paint_chicken(vars, &this->imgs[0], this->x * 64, this->y * 64);
	}
}

t_object	*new_collectible(t_vars *vars, int x, int y)
{
	t_object	*this;

	this = ft_calloc(sizeof(t_object), 1);
	if (!this)
		exit_game(vars, "Error on collectible");
	this->x = x;
	this->y = y;
	this->render = __render;
	this->imgs = ft_calloc(sizeof(t_img), 1);
	this->imgs[0] = load_img("img/Chicken/ChickenLit.xpm", vars);
	this->imgs->total_frames = 4;
	this->imgs->curr_frame = 0;
	this->imgs->curr_sprite = 0;
	return (this);
}
