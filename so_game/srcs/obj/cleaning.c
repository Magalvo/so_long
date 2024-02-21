
#include "../../headers/so_long.h"


void free_objects(t_object *head, t_vars *vars) 
{
    t_object *tmp;

    while (head != NULL)
    {
        tmp = head;
        head = head->next;
        if (tmp->imgs) {
            mlx_destroy_image(vars->mlx, tmp->imgs[0].img);
            free(tmp->imgs);
        }
        free(tmp);
    }
}

void	free_map(t_map *smap) 
{
	if (smap->map != NULL) {

		for (int i = 0; smap->map[i] != NULL; i++) {
			free(smap->map[i]);
		}
		for (int x = 0; smap->cpymap[x] != NULL; x++) {
			free(smap->cpymap[x]);
		}
		free(smap->map);
		free(smap->cpymap);
		smap->cpymap = NULL;
		smap->map = NULL;
	}
}

int exit_game(t_vars *vars, char *msg)
{
	ft_printf("%s\n", msg);
	free_objects(vars->objects, vars);
	free_map(&vars->game);
	if (vars->mlx)
	{
		mlx_destroy_image(vars->mlx, vars->canva.img);
		mlx_destroy_image(vars->mlx, vars->wall.img);
		mlx_destroy_image(vars->mlx, vars->floor.img);
		mlx_destroy_image(vars->mlx, vars->exit.img);
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
	}
	free(vars->mlx);
	exit(0);
}