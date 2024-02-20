/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:44:52 by dde-maga          #+#    #+#             */
/*   Updated: 2024/02/20 11:20:22 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

void	render_object(t_object	*obj, t_vars *vars)
{
	if(!obj || !obj->imgs || !vars)
		return ;
	paintcanva(vars, obj->imgs, obj->x, obj->y);
}

void	render_objects(t_object *list, t_vars *vars)
{
	while(list)
	{
		if(list->render)
			list->render(list, vars);
		list = list->next;
	}
}

void	init_player(t_vars *vars)
{
	t_img	player_img;
	player_img = load_img("img/char/Idle64.xpm", vars);
	vars->player = create_object(0, 0, &player_img, render_player);
	vars->player->x = vars->game.sx;
	vars->player->y = vars->game.sy;
	append_object(&vars->objects, vars->player);
}

void	render_player(t_object *this, t_vars *vars)
{
	paintcanva(vars, this->imgs, this->x, this->y);
}

void	render_colectible(t_object *this, t_vars *vars)
{
	paintcanva(vars, this->imgs, this->x, this->y);
}
