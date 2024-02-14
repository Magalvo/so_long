/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:11:05 by dde-maga          #+#    #+#             */
/*   Updated: 2024/02/14 15:19:09 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../../headers/so_long.h"

void	update_sprite(t_img *img)
{
	img->curr_sprite = (img->curr_sprite + 1) % img->total_frames;
}

int	animation_loop(t_vars *varg)
{
	const int frame_delay = 100000;
	printf("Player POS(X): %d\n Player POS(Y): %d\n", varg->person[0].curr_sx, varg->person[0].curr_sy);
	// varg->person[0].curr_sx = varg->game.player_x;
	// varg->person[0].curr_sy = varg->game.player_y;
	if (varg->move_x != 0 || varg->move_y != 0)
	{
		varg->person[0].prev_sx = varg->person[0].curr_sx;
		varg->person[0].prev_sy = varg->person[0].curr_sy;
		varg->person[0].curr_sx += varg->move_x;
		varg->person[0].curr_sy += varg->move_y;
		varg->move_x = 0;
		varg->move_y = 0;
		paintcanva(varg, &varg->person[2], varg->person[0].prev_sx,
				varg->person[0].prev_sy);
		paintcanva(varg, &varg->person[2], varg->person[0].curr_sx,
				varg->person[0].curr_sy);
	}

	// Redraw the background at the sprite's current and previous positions
	paintcanva(varg, &varg->person[2], varg->person[0].prev_sx,
			varg->person[0].prev_sy);
	paintcanva(varg, &varg->person[2], varg->person[3].curr_sx,
			varg->person[3].curr_sy);
	paintcanva(varg, &varg->person[2], varg->person[4].curr_sx,
			varg->person[4].curr_sy);
	if (varg->person[0].prev_sx != varg->person[0].curr_sx
		|| varg->person[0].prev_sy != varg->person[0].curr_sy)
	{
		paintcanva(varg, &varg->person[2], varg->person[0].curr_sx,
				varg->person[0].curr_sy);
	}
	paint_canvaw(varg, &varg->person[0]);
	paint_canvaw(varg, &varg->person[3]);
	paint_canvaw(varg, &varg->person[4]);
	update_sprite(&varg->person[0]);
	update_sprite(&varg->person[3]);
	update_sprite(&varg->person[4]);
	mlx_put_image_to_window(varg->mlx, varg->win, varg->canva.img, 0, 0);
	usleep(frame_delay);
	return (0);
}
