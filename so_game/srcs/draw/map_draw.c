/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:31:24 by dde-maga          #+#    #+#             */
/*   Updated: 2024/02/21 16:01:22 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"


void create_object_all(t_map smapi, t_vars *vars)
{
	int 		x;
	int 		y;
	t_object 	*end;
	t_object	*tmp;

	y = 0;
	end = NULL;
	while (y < smapi.height)
	{
		x = 0;
		while (x < smapi.width)
		{
			if (smapi.map[y][x] == '1' && ++x)
				continue;
			tmp = NULL;
			if (smapi.map[y][x] == 'P')
				tmp = new_player(vars, x, y);
			else if (smapi.map[y][x] == 'C')
				tmp = new_collectible(vars, x, y);
			else if (smapi.map[y][x] == 'E')
			 	tmp = new_exit(vars, x, y);
			// else if (smapi.map[y][x] == 'X')
			if (tmp)
			{
				if (vars->objects == NULL)
					vars->objects = tmp;
				else if (end)
					end->next = tmp;
				end = tmp;
			}
			smapi.map[y][x] = '0';
			x++;
		}
		y++;
	}
}


int draw_map(t_vars *vars)
{
	int x;
	int y;
	t_object *tmp;

	y = -1;
	while (++y < vars->game.height)
	{
		x = -1;
		while (++x < vars->game.width)
		{
			if (vars->game.map[y][x] == '1')
				paintcanva(vars, &vars->wall, x * 64, y * 64);
			else if (vars->game.map[y][x] == 'E')
				paintcanva(vars, &vars->exit, x * 64, y * 64);
			else if (vars->game.map[y][x] == '0')
				paintcanva(vars, &vars->floor, x * 64, y * 64);
		}
	}
	tmp = vars->objects;
	while (tmp != NULL)
	{
		tmp->render(tmp, vars);
		tmp = tmp->next;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->canva.img, 0, 0);
	return (0);
}

int init_window(t_map smapi, t_vars *vars)
{
	vars->mlx = mlx_init();
	if (!vars->mlx)
		return (0);
	ft_printf("smapi.widht: %d\n", smapi.width);
	ft_printf("smapi.height: %d\n", smapi.height);
	vars->canva.img_width = (smapi.width * 64);
	vars->canva.img_height = (smapi.height * 64);
	vars->win = mlx_new_window(vars->mlx, vars->canva.img_width , \
	vars->canva.img_height, "so_long");
	vars->canva.img = mlx_new_image(vars->mlx,  vars->canva.img_width , \
	vars->canva.img_height);
	vars->canva.addr = mlx_get_data_addr(vars->canva.img,
					&vars->canva.bits_per_pixel,
					&vars->canva.line_length,
					&vars->canva.endian);
	vars->wall = load_img("img/char/Grass64.xpm", vars);
	vars->exit = load_img("img/char/hole.xpm", vars);
	vars->floor = load_img("img/char/Pavement.xpm", vars);
	create_object_all(vars->game, vars);
	return(1);
}
