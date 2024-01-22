/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:01:17 by dde-maga          #+#    #+#             */
/*   Updated: 2024/01/22 18:17:34 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "fcntl.h"

/* char	**read_map(int fd, int ctd)
{
	char	*line;
	char	**out;
	char	*line;
	int		ctd;
	char	*line;
	int		ctd;

	line = get_next_line(fd);
	if (line)
		read_map(fd, ctd + 1);
	else
	{
		out = malloc((ctd + 1) * sizeof(char *));
		//protection
		out[ctd] = 0;
	}
	if (line)
		out[ctd] = line;
} */
//=======================================================
int	count_lines(int fd)
{
	line = get_next_line(fd);
	if (!line)
		return (0);
	ctd = 1 + count_lines(fd);
	free(line);
	return (ctd);
}

void	read_map_lines(int fd, char **map, int current_line)
{
	if (current_line <= 1)
		return ;
	map[current_line - 1] = get_next_line(fd);
	read_map_lines(fd, map, current_line - 1);
}

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

int	mapping(char *map_path, t_map *smap)
{
	int	fd;
	int	i;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
	{
		write(1, "Error opening Map\n", 18);
		return (0);
	}
	*smap = read_map(fd);
	i = validate_map(smap);
	close(fd);
	return (i);
}

void	read_map_lines(int fd, char **map, int current_line)
{
	if (current_line <= 1)
		return ;
	map[current_line - 1] = get_next_line(fd);
	read_map_lines(fd, map, current_line - 1);
}

t_map	read_map(const char *map_path)
{
	int		ln_ctd;
	t_map	smap;
	int		fd;

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

int	mapping(char *map_path, t_map *smap)
{
    int i;
	*smap = read_map(map_path);
    if (!smap->map)
    {
        write(1, "Error reading Map", 17);
        return (0);
    }
	i = validate_map(smap);
    if (i == 0)
        write(1, "Error\n", 1);
	return (i);
}