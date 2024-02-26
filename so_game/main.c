/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 10:30:35 by dde-maga          #+#    #+#             */
/*   Updated: 2024/02/26 01:03:05 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/so_long.h"

int	pick_dir(int key, t_vars *vars)
{
	if (key == KEY_W || key == KEY_UP)
		vars->pdirection = D_UP;
	else if (key == KEY_A || key == KEY_LEFT)
		vars->pdirection = D_LEFT;
	else if (key == KEY_S || key == KEY_DOWN)
		vars->pdirection = D_DOWN;
	else if (key == KEY_D || key == KEY_RIGHT)	
		vars->pdirection = D_RIGHT;
	return (0);
}
int enemy_dir(t_vars *vars)
{
    int i;

    i = rand() % 4;
    vars->xdirection = i;

    return (0);
}
int	key_hook(int key, t_vars *vars)
{
    if (key == XK_Escape)
        exit_game(vars, "The %d key (ESC) has been pressed");
    printf("The %d key has been pressed\n\n", key);
	pick_dir(key, vars);
	enemy_dir(vars);
	//move_enemy(vars->enemy, vars);
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
		mlx_key_hook(vars.win, key_hook, &vars);
		mlx_loop_hook(vars.mlx, (void *)draw_map, &vars);
		mlx_loop(vars.mlx);
	}
	return (0);
}
