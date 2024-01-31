/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:44:47 by dde-maga          #+#    #+#             */
/*   Updated: 2024/01/31 17:11:52 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

int	name_check(char *pathname)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	i = ft_strlen(pathname);
	if (i <= 4)
	{
		write(1, "Invalid Map Format", 18);
		return (0);
	}
	if (pathname[i - 1] == 'r')
		j = 1;
	if (pathname[i - 2] == 'e')
		j += 1;
	if (pathname[i - 3] == 'b')
		j += 1;
	if (pathname[i - 3] == '.')
		if (j == 0)
			write(1, "Invalid Map Format", 18);
	return (j);
}

int	validate_borders(t_map *smap)
{
	int	x;
	int	y;

	x = 0;
	while (x < smap->width)
	{
		if (smap->map[0][x] != '1' || smap->map[smap->height - 1][x] != '1')
			return (0);
		x++;
	}
	y = 0;
	while (y < smap->height)
	{
		if (smap->map[y][0] != '1' || smap->map[y][smap->width - 1])
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
			if (tile == 'c')
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
		return (0);
	switch_char(smap, &players, &exits, &collectibles);
	if (players != 1 || exits != 1 || collectibles < 0)
		return (0);
	assign_positions(smap);
	return (1);
}
