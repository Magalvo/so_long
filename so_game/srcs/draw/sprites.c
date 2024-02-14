/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:11:05 by dde-maga          #+#    #+#             */
/*   Updated: 2024/02/14 17:52:14 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../../headers/so_long.h"

void	update_sprite(t_img *img)
{
	img->curr_sprite = (img->curr_sprite + 1) % img->total_frames;
}

int	animation_loop(t_vars *varg)
{

}
