/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:01:17 by dde-maga          #+#    #+#             */
/*   Updated: 2024/02/13 11:39:57 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

void free_map(t_map *smap) {
	if (smap->map != NULL) {

		for (int i = 0; smap->map[i] != NULL; i++) {
			free(smap->map[i]);
		}

		free(smap->map);

		smap->map = NULL;
	}
}

int	open_map_file(const char *map_path)
{
	int	fd;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening map file");
		return (-1);
	}
	return (fd);
}

t_map	read_map(const char *map_path)
{
	t_map	smap = {0};
	int		fd;
	int		ln_ctd;

	ln_ctd = 0;
	fd = open_map_file(map_path);
	if (fd < 0)
		return (smap);
	read_map_lines(fd, &smap, &ln_ctd);
	if (!smap.map)
	{
		printf("readmap smap.map ERROR");
		close(fd);
		return (t_map){0};
	}
	smap.height = ln_ctd;
	if (!validate_map(&smap))
	{
		free_map(&smap);
		close(fd);
		printf("Map Not Validated on read_map\n");
		return (t_map){0};
	}
	close(fd);
	return (smap);
}

void read_map_lines(int fd, t_map *smap, int *ln_ctd)
{
	char *line;

	*ln_ctd = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		if(*ln_ctd == 0)
		{
			smap->width = ft_strlen(line);
			if(smap->width > 0 && line[smap->width - 1] == '\n')
			{
				line[smap->width - 1] = '\0';
				smap->width--;
			}
		}
	size_t old_size = (*ln_ctd) * sizeof(char *);
	size_t new_size = (old_size) + sizeof(char *);
	char **temp = (char **)ft_realloc(smap->map, old_size, new_size);

	if(!temp)
	{
		perror("Failed to allocate memory for the map lines");
		free_map(smap);
		*ln_ctd = 0;
		free(line);
		return;
	}
	smap->map = temp;
	smap->map[(*ln_ctd)++] = line;
	}

	smap->map = (char **)ft_realloc(smap->map, (*ln_ctd) * sizeof(char *), (*ln_ctd + 1) * sizeof(char *));
	if(smap->map)
	{
		smap->map[*ln_ctd] = NULL;
	}
}


int	mapping(char *map_path, t_map *smap)
{

	*smap = read_map(map_path);
	printf("Map data:\n%d\n", smap->height);
	printf("Map data:\n%d\n", smap->width);
	if (!smap->map)
	{
		write(2, "Error reading Map\n", 18);
		return (0);
	}
	if (!validate_map(smap))
	{
		write(2, "Map Validation Failed(MAPPING)\n", 31);
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
