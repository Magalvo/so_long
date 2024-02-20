/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:20:49 by dde-maga          #+#    #+#             */
/*   Updated: 2024/02/20 18:20:52 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"


static void __render(t_object *this, t_vars *vars)
{
	paintcanva(vars, &this->imgs[0], this->x * 64, this->y * 64);
}


//-1 0 +1
int	move_player(t_object *this, int sx, int sy, t_vars *vars)
{
	int	x;
	int	y;

	x = this->x + sx;
	y = this->y + sy;
	printf("x: %i y: %i\n", sx, sy);
	if (vars->game.map[y][x] == '1')
		return (0);
	printf("mx: %i my: %i\n", x, y);
	this->x = x;
	this->y = y;
	return (1);
}

t_object *new_player(t_vars *vars, int x, int y)
{
	t_object *player;

	player = ft_calloc(1, sizeof(t_object));
	if (!player)
		exit_game(vars, "er");
	vars->player = player;
	player->x = x;
	player->y = y;
	player->render = __render;
	player->imgs = ft_calloc(1, sizeof(t_img));
	player->imgs[0] = load_img("img/char/UniFox.xpm", vars);
	printf("player\n");
	return (player);
}
