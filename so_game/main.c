#include "so_long.h"

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
            j = mapping(argv[1], &vars.smap);
        if (j == 0)
            write(1, "Invalid Map Format", 18);
        if (draw_window(vars.smap, &vars) == 0)
            write(1, "Error drawing window", 21);
        draw_borders(vars.smap, &vars);
        mlx_put_image_to_window(vars.mlx, vars.win, vars.canva.img, 0, 0);
        mlx_key_hook(vars.win, key_hook, &vars);
        mlx_loop_hook(vars.mlx, &animation_loop, &vars);
        mlx_loop(vars.mlx);
        return (0);
    }
}