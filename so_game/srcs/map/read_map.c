/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:01:17 by dde-maga          #+#    #+#             */
/*   Updated: 2024/02/26 17:07:05 by dde-maga         ###   ########.fr       */
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
	if (j == 0)
		exit_game(vars, "Invalid Map Format(sec check)");
	return (j);
}


//============================READ EATCH LINE===============================//
void read_map_lines(t_vars *vars, int fd, t_map *smap, int ln_ctd)
{
	char	*line;

	line = get_next_line(fd);
	if(line)
		read_map_lines(vars, fd, smap, ln_ctd + 1);
	else if (ln_ctd > 0)
	{
		smap->map = malloc(sizeof(char *) * (ln_ctd + 1));
		smap->cpymap = malloc(sizeof(char *) * (ln_ctd + 1));
		smap->height  = ln_ctd;
	}
	if (!smap->map || !smap->cpymap)
		exit_game(vars, "das");
	if (smap->map)
	{
		smap->map[ln_ctd] = line;
		//ft_printf("%s", smap->map[ln_ctd]);
	}
	if (smap->cpymap)
		smap->cpymap[ln_ctd] = ft_strdup(line);
}

//==================READ FILE=====================//
void read_map(t_vars *vars, t_map *map, const char *map_path)
{
	int		fd;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		exit_game(vars, "Error opening map file");
	read_map_lines(vars, fd, map, 0);
	close(fd);
	if (!map->map)
		exit_game(vars, "readmap smap.map ERROR");
	if (!validate_map(vars, map))
		exit_game(vars, "Map Not Validated on read_map");
}


//===========================================MAIN FUNCTION=====================================//
int	mapping(t_vars *vars, char *map_path)
{
	read_map(vars, &vars->game, map_path);
	if(!vars->game.map)
		exit_game(vars, "Error Reading Map");
	if(!validate_map(vars, &vars->game))
		exit_game(vars, "Map Validation Failed(Mapping)");
	return (1);
}














/* void	print_map(t_vars *vars, t_map *smap)
{
	while(smap->map)
		printf()
}
 */

/* int	count_lines(int fd)
{
	char	*line;
	int		ctd;

	line = get_next_line(fd);
	if (!line)
		return (0);
	ctd = 1 + count_lines(fd);
	free(line);
	return (ctd);
} */

/*
t_map	read_map(int fd)
{
	int		ln_ctd;
	t_map	smap;

	ln_ctd = count_lines(fd);
	close(fd);
	smap.map = malloc((ln_ctd + 1) * sizeof(char *));
	if (!smap.map)
		return (smap);
	smap.map[ln_ctd] = NULL;
	smap.map[0] = get_next_line(fd);
	if (smap.map[0])
		strlen(smap.map[0]);
	read_map_lines(fd, smap.map, ln_ctd - 1);
	smap.height = ln_ctd;
	return (smap);
}

t_map	read_map(const char *map_path)
{
	int		ln_ctd;
	t_map	smap;
	int		fd;
	char	*line;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return ((t_map){0});
	ln_ctd = count_lines(fd);
	close(fd);
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return ((t_map){0});
	smap.map = malloc((ln_ctd + 1) * sizeof(char *));
	if (!smap.map)
	{
		close(fd);
		return (smap);
	}
	smap.map[ln_ctd] = NULL;
	smap.map[0] = get_next_line(fd);
	if (smap.map[0])
		smap.width = strlen(smap.map[0]);
	read_map_lines(fd, smap.map, ln_ctd - 1);
	smap.height = ln_ctd;
	return (smap);
}



 char	**read_map(int fd, int ctd, char **out)
{
	char	*line;

	line = get_next_line(fd);
	if (line)
		out = read_map(fd, ctd + 1, out);
	else if (ctd)
		out = malloc((ctd + 1) * sizeof(char *));
	if (out)
		out[ctd] = line;
	return (out);
} */
//=======================================================
