/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:44:47 by dde-maga          #+#    #+#             */
/*   Updated: 2024/02/26 21:08:31 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

int	validate_borders_width(t_vars *vars, t_map *map)
{
	size_t	x;
	size_t	y;

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
	//ft_printf("Valid Width: %d\n", map->width);
	return (1);
}

int	validate_borders_height(t_vars *vars, t_map *map)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = map->height - 1;
	while (x < map->width)
	{
		if (map->map[0][x] != '1')
			exit_game(vars, "Error Validating TOP ROW");
		x++;
	}
	x = 0;
	while(x < map->width)
	{
		if(map->map[y][x] != '1')
			exit_game(vars, "Error Validating BOTTOM ROW");
		x++;
	}
	//ft_printf("Valid Height: %d\n",  map->height);
}

int	validate_borders(t_vars *vars,t_map *map)
{
	return (validate_borders_width(vars, &vars->game)) && \
 		(validate_borders_height(vars, &vars->game));
}

int		switch_char(t_vars *vars, t_map *smap, int *players, int *exits, int *collectibles, int *sx, int *sy)
{
	char	tile;
	int		y;
	int		x;

	y = -1;
	while (++y < smap->height)
	{
		x=-1;
		while (++x < smap->width)
		{
			tile = smap->map[y][x];
			if (tile == 'P' )
			{
				*sy = y;
				*sx = x;
				(*players)++;
			}
			else if (tile == 'E')
				(*exits)++;
			else if (tile == 'C')
				(*collectibles)++;
			else if (!(tile=='X' || tile=='0' || tile=='1'))
				exit_game(vars, "Invalid Character");	
		}
	}
}

int	validate_map(t_vars *vars, t_map *map)
{
	int	players;
	int	exits;
	int	collectibles;
	int	sx;
	int	sy;

	sx = 0;
	sy = 0;
	collectibles = 0;
	exits = 0;
	players = 0;
	if (!validate_borders(vars,map))
		exit_game(vars, "Error on map validation(map_check.c)");
 	switch_char(vars, map, &players, &exits, &collectibles, &sx, &sy);
	if	(players != 1 || exits != 1 || collectibles <= 0)
		exit_game(vars, "Error Validating Items");
	map->objects_count = collectibles + 2;
	flood_fill(vars, sy, sx, map);
	map->cpymap[sy][sx] = 'P';
	ft_print_map(map->cpymap);
	if	(map->collectibles_count != collectibles || map->exit_found != 1)
		exit_game(vars, "The Fox is Trapped OR Can't find all chickens :(");
	ft_printf("ColectCount: %i\n", map->collectibles_count);
	return (1);
}
