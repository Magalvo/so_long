/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 10:30:35 by dde-maga          #+#    #+#             */
/*   Updated: 2024/02/14 17:21:51 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/so_long.h"


int main(int argc, char **argv)
{
    int j;
    static t_vars vars;
	
    j = 0;
    if (argc != 2)
	{
		ft_printf("The correct format is( ./program_name map_name.ber )\n");
		return (0);
	}
    else
    {
        j = name_check(argv[1]);

        if (j == 4)
            j = mapping(argv[1], &vars.game);
        if (j == 0)
            write(1, "Invalid Map Format(main)\n", 25);
        // if (draw_window(vars.game, &vars) == 0)
		// {
		// 	write(1, "Falha ao alocar memoria no jogo\n", 32);
		// 	return (0);
		// }
        // draw_borders(vars.game, &vars);
        // mlx_put_image_to_window(vars.mlx, vars.win, vars.canva.img, 0, 0);
    	// mlx_key_hook(vars.win, key_hook, &vars);
        // mlx_loop_hook(vars.mlx, animation_loop, &vars);
        // mlx_loop(vars.mlx);
        return (0);
    }
}
