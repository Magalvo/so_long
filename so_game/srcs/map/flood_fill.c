/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:06:45 by dde-maga          #+#    #+#             */
/*   Updated: 2024/02/21 16:14:55 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

void	flood_fill(t_vars *vars, int sy, int sx, t_map *smap)
{
 	if (smap->cpymap[sy][sx] == '1' || smap->cpymap[sy][sx] == '=')
		return ;
	if (smap->cpymap[sy][sx] == 'C')
		smap->collectibles_count++;
	if (smap->cpymap[sy][sx] == 'E')
		smap->exit_found++;
	smap->cpymap[sy][sx] = '=';
	flood_fill(vars, sy - 1, sx, smap);
	flood_fill(vars, sy + 1, sx, smap);
	flood_fill(vars, sy, sx - 1, smap);
	flood_fill(vars, sy, sx + 1, smap);
}


void	ft_print_map(char **smap)
{
	int i;

	i=0;
	while (smap[i])
	{
		ft_printf("%s", smap[i]);
		i++;
	}
}

