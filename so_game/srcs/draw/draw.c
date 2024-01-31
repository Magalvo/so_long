/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:11:17 by dde-maga          #+#    #+#             */
/*   Updated: 2024/01/31 17:11:18 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../headers/so_long.h"

void	paintcanva(t_vars *varg, t_img *img, int sx, int sy)
{
	int	x;
	int	y;

	y = 0;
	while (y < img->img_height)
	{
		x = 0;
		while (x < img->img_width)
		{
			my_mlx_pixel_put(&varg->canva, sx + x, sy + y, my_mlx_pixel_get(img,
						x, y));
			x++;
		}
		y++;
	}
}

void	paint_canvaw(t_vars *varg, t_img *img)
{
	int	frame_width;
	int	frame_x_offset;
	int	y;
	int	x;
	int	color;

	frame_width = img->img_width / img->total_frames;
	frame_x_offset = img->curr_sprite * frame_width;
	y = 0;
	while (y < img->img_height)
	{
		x = 0;
		while (x < frame_width)
		{
			color = my_mlx_pixel_get(img, frame_x_offset + x, y);
			my_mlx_pixel_put(&varg->canva, img->curr_sx + x, img->curr_sy + y,
					color);
			++x;
		}
		++y;
	}
}

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	if (color == -16777216)
	{
		return ;
	}
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	my_mlx_pixel_get(t_img *data, int x, int y)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}
