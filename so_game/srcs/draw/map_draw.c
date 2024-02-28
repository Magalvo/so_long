/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:31:24 by dde-maga          #+#    #+#             */
/*   Updated: 2024/02/28 14:07:59 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

void		render_all(t_vars *vars);

t_object	*create_object(t_vars *vars, char map_char, int x, int y)
{
	t_object	*tmp;

	tmp = NULL;
	if (map_char == 'P')
		tmp = new_player(vars, x, y);
	else if (map_char == 'C')
		tmp = new_collectible(vars, x, y);
	else if (map_char == 'E')
		tmp = new_exit(vars, x, y);
	else if (map_char == 'X')
		tmp = new_enemy(vars, x, y);
	return (tmp);
}

void	process_row(t_map smapi, t_vars *vars, t_object **end, int y)
{
	int			x;
	t_object	*tmp;

	x = 0;
	while (x < smapi.width)
	{
		if (smapi.map[y][x] == '1' && ++x)
			continue ;
		tmp = NULL;
		tmp = create_object(vars, smapi.map[y][x], x, y);
		if (tmp)
		{
			if (vars->objects == NULL)
				vars->objects = tmp;
			else if (*end)
				(*end)->next = tmp;
			*end = tmp;
		}
		smapi.map[y][x] = '0';
		x++;
	}
}

void	create_object_all(t_map smapi, t_vars *vars)
{
	int			y;
	t_object	*end;

	y = 0;
	end = NULL;
	while (y < smapi.height)
	{
		process_row(smapi, vars, &end, y);
		y++;
	}
}

int	draw_map(t_vars *vars)
{
	int			x;
	int			y;
	t_object	*tmp;

	y = -1;
	while (++y < vars->game.height)
	{
		x = -1;
		while (++x < vars->game.width)
		{
			if (vars->game.map[y][x] == '1')
				paintcanva(vars, &vars->wall, x * 64, y * 64);
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
	render_all(vars);
	return (0);
}

int	init_window(t_map smapi, t_vars *vars)
{
	vars->mlx = mlx_init();
	if (!vars->mlx)
		return (0);
	vars->canva.img_width = (smapi.width * 64);
	vars->canva.img_height = (smapi.height * 64);
	vars->win = mlx_new_window(vars->mlx, vars->canva.img_width,
			vars->canva.img_height, "Fantastic Mister Fox");
	vars->canva.img = mlx_new_image(vars->mlx, vars->canva.img_width,
			vars->canva.img_height);
	vars->canva.addr = mlx_get_data_addr(vars->canva.img,
			&vars->canva.bits_per_pixel,
			&vars->canva.line_length,
			&vars->canva.endian);
	vars->wall = load_img("img/char/Grass64.xpm", vars);
	vars->floor = load_img("img/char/Pavement.xpm", vars);
	create_object_all(vars->game, vars);
	return (1);
}
