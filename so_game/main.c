#include "./headers/so_long.h"

int	key_hook(int keycode, t_vars *vars)
{
	vars->person[0].prev_sx = vars->person[0].curr_sx;
	vars->person[0].prev_sy = vars->person[0].curr_sy;
	if (keycode == XK_Escape)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		exit(0);
	}
	else if (keycode == XK_w && vars->person[0].curr_sy > 0)
	{
		vars->move_y -= 64;
		ft_printf("curr_sy: %d\n", vars->person[0].curr_sy);
		ft_printf("curr_sx: %d\n", vars->person[0].curr_sx);
	}
	else if (keycode == XK_s && vars->person[0].curr_sy < 576)
	{
		vars->move_y += 64;
		ft_printf("curr_sy: %d\n", vars->person[0].curr_sy);
		ft_printf("curr_sx: %d\n", vars->person[0].curr_sx);
	}
	else if (keycode == XK_a && vars->person[0].curr_sx > 0)
	{
		vars->move_x -= 64;
		ft_printf("curr_sx: %d\n", vars->person[0].curr_sx);
		ft_printf("curr_sy: %d\n", vars->person[0].curr_sy);
	}
	else if (keycode == XK_d && vars->person[0].curr_sx < 576)
	{
		vars->move_x += 64;
		ft_printf("curr_sx: %d\n", vars->person[0].curr_sx);
		ft_printf("curr_sy: %d\n", vars->person[0].curr_sy);
	}
	//ft_printf("keycode: %d\n", keycode);
	return (0);
}


int main(int argc, char **argv)
{
    int j;
    t_vars vars;

    j = 0;
    if (argc != 2)
        return (0);
    if (argc == 2)
    {
        j = name_check(argv[1]);
        if (j == 4)
            j = mapping(argv[1], &vars.game);
        if (j == 0)
            write(1, "Invalid Map Format", 18);
        if (draw_window(vars.game, &vars) == 0)
            write(1, "Error drawing window", 21);
        draw_borders(vars.game, &vars);
        mlx_put_image_to_window(vars.mlx, vars.win, vars.canva.img, 0, 0);
        mlx_key_hook(vars.win, key_hook, &vars);
        mlx_loop_hook(vars.mlx, &animation_loop, &vars);
        mlx_loop(vars.mlx);
        return (0);
    }
}
