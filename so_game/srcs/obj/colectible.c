/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colectible.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:20:43 by dde-maga          #+#    #+#             */
/*   Updated: 2024/02/20 18:20:44 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../../headers/so_long.h"


static void __render(t_object *this, t_vars *vars)
{
	paintcanva(vars, &this->imgs[0], this->x * 64, this->y * 64);
}

t_object *new_colectacle(t_vars *vars, int x, int y)
{
	t_object *this;

	this = ft_calloc(1, sizeof(t_object));
	if (!this)
		exit_game(vars, "er");
	this->x = x;
	this->y = y;
	this->render = __render;
	this->imgs = ft_calloc(1, sizeof(t_img));
	this->imgs[0] = load_img("img/char/UniChicken.xpm", vars);
	printf("this\n");
	return (this);
}
