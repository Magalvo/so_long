/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:37:01 by dde-maga          #+#    #+#             */
/*   Updated: 2024/02/27 10:37:05 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

void	collect_item(t_vars *vars, int x, int y)
{
	t_object	*current;

	current = vars->objects;
	while (current != NULL)
	{
		if (current->x == x && current->y == y && !current->collected)
		{
			current->collected = 1;
			break ;
		}
		current = current->next;
	}
	vars->game.collectibles_count -= 1;
}
