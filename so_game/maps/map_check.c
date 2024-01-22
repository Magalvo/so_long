/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:44:47 by dde-maga          #+#    #+#             */
/*   Updated: 2024/01/22 18:44:46 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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

int	validate_map(t_map *smap)
{
	int	players;
	int	exits;
	int	collectibles;

	players = 0;
	exits = 0;
	collectibles = 0;
	if (validate_borders(smap));
    {
        int y;
        int x;
        
        y=0;
        while (y < smap->height)
        {
            x = 0;
            while (x < smap->width)
            {
                if (smap->map[y][x] == 'P')
                {
                    players++;
                    smap->player_x = x;
                    smap->player_y = y;
                }
                else if (smap->map[y][x] == 'E')
                {
                    exits++;
                    smap->exit_x = x;
                    smap->exit_y = y;
                }
                else if (smap->map[y][x] == 'C')
                    collectibles++;
                x++;
            }
        }
        y++;
    }

    if (players != 1 || exits != 1 || collectibles < 1)
        return 0;
    return (1);
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


int switch_char()