/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:11:11 by dde-maga          #+#    #+#             */
/*   Updated: 2024/02/19 17:10:03 by dde-maga         ###   ########.fr       */
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

void	loadallimg(t_vars *vars)
{
	// vars->person = ft_calloc(sizeof(t_img), 5);
	// if(!vars->person)
	// 	return ;
	// vars->person[0] = load_img("img/char/Idle64.xpm", vars);
	// vars->person[1] = load_img("img/char/Pavement.xpm", vars);
	// vars->person[2] = load_img("img/char/Grass64.xpm", vars);
	// vars->person[3] = load_img("img/char/ChickenLit.xpm", vars);
	// //vars->person[4] = load_img("img/char/Lion.xpm", vars);
	// vars->person[4] = load_img("img/char/hole.xpm", vars);
}
