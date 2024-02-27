/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:37:22 by dde-maga          #+#    #+#             */
/*   Updated: 2024/02/27 17:29:24 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

void	free_objects(t_object *head, t_vars *vars)
{
	t_object	*tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		if (tmp->imgs)
		{
			mlx_destroy_image(vars->mlx, tmp->imgs[0].img);
			free(tmp->imgs);
		}
		free(tmp);
	}
}

void	free_map(t_map *smap)
{
	int	i;
	int	x;

	if (smap->map != NULL)
	{
		i = 0;
		while (smap->map[i] != NULL)
		{
			free(smap->map[i]);
			i++;
		}
		x = 0;
		while (smap->cpymap[x] != NULL)
		{
			free(smap->cpymap[x]);
			x++;
		}
		free(smap->map);
		free(smap->cpymap);
		smap->cpymap = NULL;
		smap->map = NULL;
	}
}

int	exit_game(t_vars *vars, char *msg)
{
	ft_printf("%s\n", msg);
	free_objects(vars->objects, vars);
	free_map(&vars->game);
	if (vars->mlx)
	{
		mlx_destroy_image(vars->mlx, vars->canva.img);
		mlx_destroy_image(vars->mlx, vars->wall.img);
		mlx_destroy_image(vars->mlx, vars->floor.img);
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
	}
	free(vars->mlx);
	exit(0);
}

int	close_window(t_vars *vars)
{
	exit_game(vars, "Game Closed, shutting down...\n");
	return (1);
}
