/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:44:47 by dde-maga          #+#    #+#             */
/*   Updated: 2024/02/20 21:39:47 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

int exit_game(t_vars *vars, char *msg)
{
	ft_printf("%s\n", msg);
	free_map(&vars->game);
	if (vars->mlx)
	{
		mlx_destroy_image(vars->mlx, vars->canva.img);
		mlx_destroy_image(vars->mlx, vars->wall.img);
		mlx_destroy_image(vars->mlx, vars->floor.img);
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
	}
	free(vars->mlx);
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
	ft_printf("Valid Width: %d\n", map->width);
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
	ft_printf("Valid Height: %d\n",  map->height);
}

int	validate_borders(t_vars *vars,t_map *map)
{
	return (validate_borders_width(vars, &vars->game)) && \
 		(validate_borders_height(vars, &vars->game));
}

void	switch_char(t_vars *vars, t_map *smap, int *players, int *exits, int *collectibles, int *sx, int *sy)
{
	char	tile;
	int		y;
	int		x;

	y = 0;
	while (y < smap->height)
	{
		x=0;
		while (x < smap->width)
		{
			tile = smap->map[y][x];
			if (tile == 'P' && (*players) == 0)
			{
				*sy = y;
				*sx = x;
				(*players)++;
			}
			if (tile == 'E')
				(*exits)++;
			if (tile == 'C')
				(*collectibles)++;
			x++;
		}
		y++;
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
	if	(map->collectibles_count <= 0 || map->exit_found != 1)
		exit_game(vars, "The Fox is Trapped OR Can't find any chickens :(");
	ft_printf("Finish Verify\n");
	return (1);
}
