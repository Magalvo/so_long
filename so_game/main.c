/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 10:30:35 by dde-maga          #+#    #+#             */
/*   Updated: 2024/02/28 14:41:27 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/so_long.h"

int	pick_dir(int key, t_vars *vars)
{
	if (key == KEY_W)
		vars->pdirection = D_UP;
	else if (key == KEY_A)
		vars->pdirection = D_LEFT;
	else if (key == KEY_S)
		vars->pdirection = D_DOWN;
	else if (key == KEY_D)
		vars->pdirection = D_RIGHT;
	return (0);
}

void	enemy_dir(t_vars *vars)
{
	int	i;

	i = rand() % 4;
	vars->xdirection = i;
}

int	key_hook(int key, t_vars *vars)
{
	if (key == XK_Escape)
		exit_game(vars, "The %d key (ESC) has been pressed");
	else if (key == 17)
		exit_game(vars, "The %d key (ESC) has been pressed");
	pick_dir(key, vars);
	if (key == XK_d || key == XK_a || key == XK_s || key == XK_w)
	{
		move_player(vars->player, (key == XK_d) - (key == XK_a), \
			(key == XK_s) - (key == XK_w), vars);
	}
	return (0);
}

void	ft_print_banner(void)
{
	ft_printf("-----------------------------------");
	ft_printf("---------------------------------------\n");
	ft_printf("|   ______          _            _   _        ");
	ft_printf("__  __      ______         |\n");
	ft_printf("|  |  ____|        | |          | | (_)      |  ");
	ft_printf("\\/  |    |  ____|        |\n");
	ft_printf("|  | |__ __ _ _ __ | |_ __ _ ___| |_ _  ___  | ");
	ft_printf("\\  / |_ __| |__ _____  __ |\n");
	ft_printf("|  |  __/ _` | '_ \\| __/ _` / __| __| |/ __| | ");
	ft_printf("|\\/| | '__|  __/ _ \\ \\/ / |\n");
	ft_printf("|  | | | (_| | | | | || (_| \\__ \\ |_| | (__  ");
	ft_printf("| |  | | |_ | | | (_) >  <  |\n");
	ft_printf("|  |_|  \\__,_|_| |_|\\__\\__,_|___/\\__|_|");
	ft_printf("\\___| |_|  |_|_(_)|_|  \\___/_/\\_\\ |\n");
	ft_printf("------------------------------------");
	ft_printf("--------------------------------------\n\n");
}

int	main(int argc, char **argv)
{
	static t_vars	vars;

	if (argc != 2)
		ft_printf("The correct format is( ./program_name map_name.ber )\n");
	else
	{
		ft_print_banner();
		name_check(&vars, argv[1]);
		mapping(&vars, argv[1]);
		if (init_window(vars.game, &vars) == 0)
			exit_game(&vars, "Failed to draw window");
		mlx_hook(vars.win, 17, 0, close_window, &vars);
		mlx_key_hook(vars.win, key_hook, &vars);
		mlx_loop_hook(vars.mlx, (void *)move_enemy, &vars.enemy);
		mlx_loop_hook(vars.mlx, (void *)draw_map, &vars);
		mlx_loop(vars.mlx);
	}
	return (0);
}
