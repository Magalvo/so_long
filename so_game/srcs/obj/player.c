/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:20:49 by dde-maga          #+#    #+#             */
/*   Updated: 2024/02/22 18:13:39 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"


static void __render(t_object *this, t_vars *vars)
{
	paint_canvaw(vars, &this->imgs[0], this->x * 64, this->y * 64);
	update_sprite(vars->player->imgs);
}

int	pick_dir(t_object *this, int x, int y, t_vars *vars)
{
	if (x == 1)
		this->imgs->curr_frame = 64;
	if (x == -1)
		this->imgs->curr_frame = 128;
	if (y == 1)
		this->imgs->curr_frame = 0;
	if (y == -1)
		this->imgs->curr_frame = 192;
	return(1);
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
	if (vars->game.map[y][x] == 'X')
		exit_game(vars, "Your where slained by the farmer!");
	pick_dir(this, x, y, vars);
	printf("mx: %i my: %i\n", x, y);
	this->x = x;
	this->y = y;
	return (1);
}

t_object *new_player(t_vars *vars, int x, int y)
{
	t_object *player;

	player = ft_calloc(sizeof(t_object), 1);
	if (!player)
		exit_game(vars, "error on new player");
	vars->player = player;
	player->x = x;
	player->y = y;
	player->render = __render;
	player->imgs = ft_calloc(sizeof(t_img),1);
	player->imgs[0] = load_img("img/Player/FoxAll.xpm", vars);
	player->imgs->total_frames = 3;
	player->imgs->curr_frame = 0;
	player->imgs->curr_sprite = 0;
	printf("player\n");
	return (player);
}

