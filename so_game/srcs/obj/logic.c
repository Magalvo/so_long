/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:37:01 by dde-maga          #+#    #+#             */
/*   Updated: 2024/02/28 14:19:31 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

void	collect_item(t_vars *vars, int x, int y)
{
	t_object	*current;

	current = vars->objects;
	while (current != NULL)
	{
		if (current->x == x && current->y == y && current->collected != 1)
		{
			current->collected = 1;
			vars->game.collectibles_count -= 1;
		}
		current = current->next;
	}
}

int	chk_loc(t_vars *vars, int x, int y)
{
	t_object	*current;

	current = vars->objects;
	while (current != NULL)
	{
		if (current->x == x && current->y == y && !current->collected)
			return (1);
		current = current->next;
	}
	return (0);
}
