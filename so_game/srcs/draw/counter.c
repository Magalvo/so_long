/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:36:36 by dde-maga          #+#    #+#             */
/*   Updated: 2024/02/27 11:56:12 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

void	display_counter(t_vars *vars, int x, int y, int number)
{
	char	*num_str;

	num_str = ft_itoa(number);
	if (!num_str)
		exit_game(vars, "Failed counter conv");
	mlx_string_put(vars->mlx, vars->win, x, y, 0xFFFFFF, num_str);
	free(num_str);
}

bool	check_time(long long *last_time)
{
	struct timeval	tv;
	long long		current_time;

	gettimeofday(&tv, NULL);
	current_time = tv.tv_sec * 1000000 + tv.tv_usec;
	if (current_time - *last_time >= FRAME_TIME)
	{
		*last_time = current_time;
		return (true);
	}
	else
		return (false);
}
