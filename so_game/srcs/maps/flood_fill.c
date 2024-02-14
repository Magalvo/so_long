/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:06:45 by dde-maga          #+#    #+#             */
/*   Updated: 2024/02/14 17:24:38 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

void	flood_fill(int sy, int sx, t_map *smap)
{
	if (sy < 0 || sy >= smap->height || sx < 0 || sx >= smap->width
		|| smap->cpymap[sy][sx] == '1' || smap->cpymap[sy][sx] == '3')
		return ;
	if (smap->cpymap[sy][sx] == 'C')
		smap->collectibles_found++;
	if (smap->cpymap[sy][sx] == 'E')
		smap->exit_found++;
	smap->cpymap[sy][sx] = '3';
	flood_fill(sy + 1, sx, smap);
	flood_fill(sy - 1, sx, smap);
	flood_fill(sy, sx + 1, smap);
	flood_fill(sy, sx - 1, smap);
}
