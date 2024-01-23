/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:03:04 by dde-maga          #+#    #+#             */
/*   Updated: 2024/01/23 17:08:52 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	map_main(int argc[], char *argv)
{
	int		j;
	t_vars	vars;

	j = name_check(argv[1]);
	if (j == 4)
		mapping(argv[1], &vars.game);
	else
		write(1, "Error", 5);
	if (j == 0)
		return (0);
}
