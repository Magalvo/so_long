/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:44:47 by dde-maga          #+#    #+#             */
/*   Updated: 2024/02/14 17:13:49 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"
#include <unistd.h>

int	name_check(char *pathname)
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
		write(1, "Invalid Map Format(sec check)", 29);
	return (j);
}

int	validate_borders(t_map *smap)
{
	int	x;
	int	y;

	x = 0;
	printf("Width %d\n", smap->width);
	printf("Height %d\n", smap->height);
	while (x < smap->width)
	{
		if (smap->map[0][x] != '1' || smap->map[smap->height - 1][x] != '1')
			return (0);
		x++;
	}
	y = 0;
	while (y < smap->height)
	{
		if (smap->map[y][0] != '1' || smap->map[y][smap->width - 1] != '1')
			return (0);
		y++;
	}
	return (1);
}

void	assign_positions(t_map *smap)
{
	int x;
	int y;
	char tile;

	y = 0;
	while (y < smap->height)
	{
		x=0;
		while (x < smap->width)
		{
			tile = smap->map[y][x];
			if (tile == 'P')
			{
				smap->player_x = x;
				smap->player_y = y;
			}
			if (tile == 'E')
			{
				smap->exit_x = x;
				smap->exit_y = y;
			}
			if(tile == 'X')
			{
				smap->enemy_x = x;
				smap->enemy_y = y;
 			}
			x++;
		}
		y++;
	}
}

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

int	validate_map(t_map *smap)
{
	int players;
	int exits;
	int collectibles;

	if (!validate_borders(smap))
	{
		printf("Error on validate Map/Borders\n");
		return (0);
	}

	printf("Valid Borders\n");
	switch_char(smap, &players, &exits, &collectibles);
	if (players != 1 || exits != 1 || collectibles <= 0)
		return (0);
	assign_positions(smap);
	return (1);
}
