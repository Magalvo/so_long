/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 10:30:35 by dde-maga          #+#    #+#             */
/*   Updated: 2024/02/20 18:27:56 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/so_long.h"

int	key_hook(int key, t_vars *vars)
{
    if (key == XK_Escape)
        exit_game(vars, "The %d key (ESC) has been pressed");
    printf("The %d key has been pressed\n\n", key);
	move_player(vars->player, (key == XK_d) - (key == XK_a), \
	(key == XK_s) - (key == XK_w), vars);
    return (0);
}


int main(int argc, char **argv)
{
	static t_vars vars;

	if (argc != 2)
		ft_printf("The correct format is( ./program_name map_name.ber )\n");
	else
	{
		name_check(&vars, argv[1]);
		mapping(&vars, argv[1]);
		if (init_window(vars.game, &vars) == 0)
			exit_game(&vars, "Failed to draw window");
		// if (draw_borders(vars.game, &vars) == 0)
		// 	exit_game(&vars, "Failed to draw borders");
		// mlx_put_image_to_window(vars.mlx, vars.win, vars.canva.img, 0, 0);
		mlx_key_hook(vars.win, key_hook, &vars);
		mlx_loop_hook(vars.mlx, (void *)draw_map, &vars);
		mlx_loop(vars.mlx);
		exit_game(&vars, "Finished running program");
	}
	return (0);
}
