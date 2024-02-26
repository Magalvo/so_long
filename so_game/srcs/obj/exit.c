/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:20:35 by dde-maga          #+#    #+#             */
/*   Updated: 2024/02/26 17:16:46 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"


static void __render(t_object *this, t_vars *vars)
{
	if(vars->game.collectibles_count == 0)
	{
		paintcanva(vars, &this->imgs[0], this->x * 64, this->y * 64);
		if(vars->player->x == this->x && vars->player->y == this->y)
			exit_game(vars,"Congratulations Mr.Fox, you Won!\n");
	}	
}

t_object *new_exit(t_vars *vars, int x, int y)
{
	t_object *exit;

	exit = ft_calloc(1, sizeof(t_object));
	if (!exit)
		exit_game(vars, "er");
	exit->x = x;
	exit->y = y;
	exit->render = __render;
	exit->imgs = ft_calloc(1, sizeof(t_img));
	exit->imgs[0] = load_img("img/char/hole.xpm", vars);
	//ft_printf("exit\n");
	return (exit);
}

