/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:44:47 by dde-maga          #+#    #+#             */
/*   Updated: 2024/02/16 17:57:26 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"
#include <unistd.h>



int exit_game(t_vars *vars, char *msg)
{
	ft_printf("%s\n", msg);
	free_map(&vars->game);
	exit(0);
}

int	name_check(t_vars *vars, char *pathname)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	i = ft_strlen(pathname);
	if (i <= 4)
		return (!write(1, "Invalid Map Format(map_check)", 29));
	if (pathname[i - 1] == 'r')
		j = 1;
	if (pathname[i - 2] == 'e')
		j += 1;
	if (pathname[i - 3] == 'b')
		j += 1;
	if (pathname[i - 4] == '.')
		j += 1;
	if (j == 0)
		exit_game(vars, "Invalid Map Format(sec check)");
	return (j);
}

int validate_borders_height(t_vars *vars, t_map *map)
{
	size_t	x;
	size_t	y;

	x = 0;
	while(map->map[y])
	{
		y=0;
		while(map->map[y][x] && map->map[y][x] != '\n')
			y++;
		if (y == 0 || map->map[0][x] != '1' || map->map[y - 1][x] != '1')
			exit_game(vars, "Error Validating Borders HEIGHT");
		if (x == 0)
			map->height = y;
		else if (y != map->height)
			exit_game(vars, "Error Validating Borders HEIGHT");
		x++;
	}
	printf("Height %d\n", map->height);
	return (1);
}

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
	printf("Width %d\n", map->width);
	return (1);
}

int	validate_borders(t_vars *vars,t_map *map)
{
	return (validate_borders_width(vars, &vars->game) && \
			validate_borders_height(vars, &vars->game));
}

// void	load_map_objects(t_map *smap)
// {
// 	int x;
// 	int y;
// 	char tile;

// 	y = 0;
// 	while (y < smap->height)
// 	{
// 		x=0;
// 		while (x < smap->width)
// 		{
// 			tile = smap->map[y][x];
// 			// if (tile == 'P')
// 			// {
// 			// 	smap->player_x = x;
// 			// 	smap->player_y = y;
// 			// }
// 			// if (tile == 'E')
// 			// {
// 			// 	smap->exit_x = x;
// 			// 	smap->exit_y = y;
// 			// }
// 			// if(tile == 'X')
// 			// {
// 			// 	smap->enemy_x = x;
// 			// 	smap->enemy_y = y;
//  			// }
// 			x++;
// 		}
// 		y++;
// 	}
// }

int switch_char(t_map *smap, int *players, int *exits, int *collectibles)
{
	int x;
	int y;
	char tile;

	*players = 0;
	*exits = 0;
	*collectibles = 0;
	y = 0;
	while (y < smap->width)
	{
		x=0;
		while (x < smap->width)
		{
			tile = smap->map[y][x];
			if (tile == 'P')
				(*players)++;
			if (tile == 'E')
				(*exits)++;
			if (tile == 'C')
				(*collectibles)++;
			x++;
		}
		y++;
	}
	return(1);
}

int	validate_map(t_vars *vars, t_map *map)
{
	// int players;
	// int exits;
	// int collectibles;

	if (!validate_borders(vars,map))
		exit_game(vars, "Error on map validation(map_check.c)");
	if (!flood_fill())
	//switch_char(map, &players, &exits, &collectibles);
	// if (players != 1 || exits != 1 || collectibles <= 0)
	// 	exit_game(vars, "Error Validating Items");
	// assign_positions(map);
	return (1);
}
