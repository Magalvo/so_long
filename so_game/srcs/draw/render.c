/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:44:52 by dde-maga          #+#    #+#             */
/*   Updated: 2024/02/19 18:22:38 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

void	render_object(t_object	*obj, t_vars *vars)
{
	if(!obj || !obj->imgs || !vars)
		return ;
	paintcanva(vars, obj->imgs, obj->x, obj->y);
}

t_object *create_object(int x, int y, t_img *imgs, void (*render)(t_object *))
{
	t_object *obj = ft_calloc(sizeof(t_object), 1);
	if (!obj)
		return NULL;
	obj->x = x;
	obj->y = y;
	obj->imgs = imgs;
	obj->render = render;
	obj->next = NULL;

	return obj;
}

void	append_object(t_object **list, t_object *new_obj)
{
	if (!*list)
		*list = new_obj;
	else
	{
		t_object *tmp = *list;
		while (tmp ->next)
		{
			tmp = tmp->next;
		}
		tmp->next = new_obj;
	}
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

void render_colectible(t_object *this, t_vars *vars)
{
	paintcanva(vars, this->imgs, this->x, this->y);
}
