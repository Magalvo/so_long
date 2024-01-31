/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:31:24 by dde-maga          #+#    #+#             */
/*   Updated: 2024/01/31 17:10:53 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

void    char_map(char map, t_vars *vars, int sx, int sy)
{
    if (map == '0' || map == 'C' || map == 'P')
        paintcanva(vars, &vars->person[1], sx, sy);
    else if (map == 'C')
        paintcanva(vars, &vars->person[3], sx, sy);
    else if (map == 'E')
        paintcanva(vars, &vars->person[2], sx, sy);
    else if (map == 'P')
        paintcanva(vars, &vars->person[0], sx, sy);
    else if (map == '1')
        paintcanva(vars, &vars->person[2], sx, sy);
    else
        write(1, "Invalid Map Format", 18);
}

int draw_borders(t_map smapi, t_vars *vars)
{
    int x;
    int y;

    y = 0;
    while (y < smapi.height)
    {
        x = 0;
        while (x < smapi.width)
        {
            char_map(smapi.map[y][x], vars, x * 64, y * 64);
            x++;
        }
        y++;
    }
    return (0);
}

int draw_window(t_map smapi, t_vars *vars)
{
    vars->mlx = mlx_init();
    vars->win = mlx_new_window(vars->mlx, smapi.width * 64, smapi.height * 64, "so_long");
    vars->canva.img = mlx_new_image(vars->mlx, smapi.width * 64, smapi.height * 64);
    vars->canva.addr = mlx_get_data_addr(vars->canva.img, &vars->canva.bits_per_pixel, &vars->canva.line_length, &vars->canva.endian);
    loadallimg(vars);
    return(1);
}
