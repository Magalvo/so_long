/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:11:11 by dde-maga          #+#    #+#             */
/*   Updated: 2024/02/21 16:50:08 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../../headers/so_long.h"

t_img	load_img(char *path, t_vars *varg)
{
	t_img	img;

	if(varg->mlx)
		printf("Good Init\n");
	img.relative_path = path;
	img.img = mlx_xpm_file_to_image(varg->mlx, img.relative_path, &img.img_width,
			&img.img_height);
 	if (!img.img)
		exit_game(varg, "error on image conversion");
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	if(!img.addr)
		exit_game(varg, "Error on image addressing");
	return (img);
}
