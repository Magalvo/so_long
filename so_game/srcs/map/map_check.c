/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:44:47 by dde-maga          #+#    #+#             */
/*   Updated: 2024/02/28 14:43:18 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

int	validate_borders_width(t_vars *vars, t_map *map)
{
	int	x;
	int	y;

	map->width = -1;
	y = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x] && map->map[y][x] != '\n')
			x++;
		if (x == 0 || map->map[y][0] != '1' || map->map[y][x - 1] != '1')
			exit_game(vars, "Error Validating Borders WIDTH");
		if (y == 0)
			map->width = x;
		else if (x != map->width)
			exit_game(vars, "Error Validating Borders WIDHT");
		y++;
	}
	return (1);
}

int	validate_borders_height(t_vars *vars, t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = map->height - 1;
	while (x < map->width)
	{
		if (map->map[0][x] != '1')
			exit_game(vars, "Error Validating TOP ROW");
		x++;
	}
	x = 0;
	while (x < map->width)
	{
		if (map->map[y][x] != '1')
			exit_game(vars, "Error Validating BOTTOM ROW");
		x++;
	}
	return (1);
}

int	validate_borders(t_vars *vars)
{
	return ((validate_borders_width(vars, &vars->game)) && \
			(validate_borders_height(vars, &vars->game)));
}

void	switch_char(t_vars *vars, t_val *temp)
{
	char	tile;
	int		y;
	int		x;

	y = -1;
	while (++y < vars->game.height)
	{
		x = -1;
		while (++x < vars->game.width)
		{
			tile = vars->game.map[y][x];
			if (tile == 'P')
			{
				temp->sy = y;
				temp->sx = x;
				temp->players++;
			}
			else if (tile == 'E')
				temp->exits++;
			else if (tile == 'C')
				temp->collectibles++;
			else if (!(tile == 'X' || tile == '0' || tile == '1'))
				exit_game(vars, "Invalid Character");
		}
	}
}

int	validate_map(t_vars *vars, t_map *map)
{
	if (!validate_borders(vars))
		exit_game(vars, "Error on map validation(map_check.c)");
	switch_char(vars, &vars->val);
	if (vars->val.players != 1 || vars->val.exits != 1
		|| vars->val.collectibles <= 0)
		exit_game(vars, "Error Validating Items");
	map->objects_count = vars->val.collectibles + 2;
	flood_fill(vars, vars->val.sy, vars->val.sx, map);
	if (map->collectibles_count != vars->val.collectibles
		|| map->exit_found != 1)
		exit_game(vars, "The Fox is Trapped OR Can't find all chickens :(");
	return (1);
}
