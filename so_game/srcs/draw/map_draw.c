/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:31:24 by dde-maga          #+#    #+#             */
/*   Updated: 2024/02/20 11:43:57 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

/* void	char_map(char map, t_vars *vars, int sx, int sy)
{
	if (map == '0')
		paintcanva(vars, &vars->, sx * 64, sy* 64);
	else if (map == 'C')
		paintcanva(vars, &vars->person[3], sx * 64, sy* 64);
	else if (map == 'E')
		paintcanva(vars, &vars->person[4], sx * 64, sy* 64);
	else if (map == 'P')
		paintcanva(vars, &vars->person[0], sx * 64, sy* 64);
	else if (map == '1')
		paintcanva(vars, &vars->person[2], sx * 64, sy* 64);
	else
		exit_game(vars, "Invalid Map Format(map_draw)");
} */

int draw_borders(t_map smapi, t_vars *vars)
{
	int x;
	int y;

	y = 0;
	while (y < smapi.height)
	{
		x = 0;
		while (x < smapi.width)
		{
			char_map(smapi.map[y][x], vars, x, y);
			x++;
		}
		y++;
	}
	return (0);
}

int draw_window(t_map smapi, t_vars *vars)
{
	vars->mlx = mlx_init();
	printf("smapi.widht: %d\n", smapi.width);
	vars->win = mlx_new_window(vars->mlx, (smapi.width * 64), (smapi.height * 64), "so_long");
	vars->canva.img = mlx_new_image(vars->mlx, (smapi.width * 64), (smapi.height * 64));
	vars->canva.addr = mlx_get_data_addr(vars->canva.img,
					&vars->canva.bits_per_pixel,
					&vars->canva.line_length,
					&vars->canva.endian);
	init_player(vars);
	return(1);
}
