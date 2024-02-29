/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:01:17 by dde-maga          #+#    #+#             */
/*   Updated: 2024/02/27 18:39:42 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

//============================EXTENSION CHECK===============================//
int	name_check(t_vars *vars, char *pathname)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	i = ft_strlen(pathname);
	if (i <= 4)
		return (!write(1, "Invalid Map Format(map_check)", 29));
	if (pathname[i - 1] == 'r')
		j = 1;
	if (pathname[i - 2] == 'e')
		j += 1;
	if (pathname[i - 3] == 'b')
		j += 1;
	if (pathname[i - 4] == '.')
		j += 1;
	if (j != 4)
		exit_game(vars, "Invalid Map Format(sec check)");
	return (j);
}

//============================READ EATCH LINE===============================//
void	read_map_lines(t_vars *vars, int fd, t_map *smap, int ln_ctd)
{
	char	*line;

	line = get_next_line(fd);
	if (line)
		read_map_lines(vars, fd, smap, ln_ctd + 1);
	else if (ln_ctd > 0)
	{
		smap->map = malloc(sizeof(char *) * (ln_ctd + 1));
		smap->cpymap = malloc(sizeof(char *) * (ln_ctd + 1));
		smap->height = ln_ctd;
	}
	if (!smap->map || !smap->cpymap)
		exit_game(vars, "das");
	if (smap->map)
	{
		smap->map[ln_ctd] = line;
	}
	if (smap->cpymap)
		smap->cpymap[ln_ctd] = ft_strdup(line);
}

//==================READ FILE=====================//
void	read_map(t_vars *vars, t_map *map, const char *map_path)
{
	int	fd;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		exit_game(vars, "Error opening map file");
	read_map_lines(vars, fd, map, 0);
	close(fd);
	if (!map->map)
		exit_game(vars, "readmap smap.map ERROR");
}

//=================MAIN FUNCTION===============//
int	mapping(t_vars *vars, char *map_path)
{
	read_map(vars, &vars->game, map_path);
	if (!vars->game.map)
		exit_game(vars, "Error Reading Map");
	if (!validate_map(vars, &vars->game))
		exit_game(vars, "Map Validation Failed(Mapping)");
	return (1);
}
