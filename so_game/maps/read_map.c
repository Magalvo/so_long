/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:01:17 by dde-maga          #+#    #+#             */
/*   Updated: 2024/01/24 15:57:42 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "fcntl.h"

int	open_map_file(const char *map_path)
{
	int	fd;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (-1);
	return (fd);
}

t_map	read_map(const char *map_path)
{
	t_map	smap = {0};
	int		fd;
	int		ln_ctd;

	fd = open_map_file(map_path);
	if (fd < 0)
		return (smap);
	smap.map = NULL;
	read_map_lines(fd, &smap, &ln_ctd);
	smap.height = ln_ctd;
	close(fd);
	return (smap);
}

void	read_map_lines(int fd, t_map *smap, int *ln_ctd)
{
	char *line;
	
	*ln_ctd = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		if (*ln_ctd == 0)
			smap->width = ft_strlen(line);
		smap->map = (char **)ft_reallloc(smap->map, (*ln_ctd) * sizeof(char *),
				(*ln_ctd + 1) * sizeof(char *));
		smap->map[*ln_ctd] = line;
		(*ln_ctd)++;
	}
	smap->map = (char **)ft_realloc(smap->map, (*ln_ctd) * sizeof(char *),
			(*ln_ctd + 1) * sizeof(char *));
	smap->map[*ln_ctd] = NULL;
}

int	mapping(char *map_path, t_map *smap)
{
	int	i;

	*smap = read_map(map_path);
	if (!smap->map)
	{
		write(1, "Error reading Map", 17);
		return (0);
	}
	i = validate_map(smap);
	if (!i)
	{
		write(1, "Map Validation Failed\n", 23);
		return (0);
	}
	return (1);
}







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



 char	**read_map(int fd, int ctd)
{
	char	*line;
	char	**out;
	char	*line;
	int		ctd;
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
