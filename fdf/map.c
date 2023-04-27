/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgarriss <tgarriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:41:38 by tgarriss          #+#    #+#             */
/*   Updated: 2022/05/12 15:28:53 by tgarriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_map_width(char *path)
{
	char	**array;
	char	*line;
	int		width;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		ft_error("open() failed.", __FILE__, __func__, __LINE__);
	line = get_next_line(fd);
	array = ft_split(line, ' ');
	width = 0;
	while (array[width])
		width++;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	ft_free_carray(array);
	return (width);
}

int	get_map_height(char *path)
{
	char	*line;
	int		height;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		ft_error("open() failed.", __FILE__, __func__, __LINE__);
	height = 0;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		height++;
	}
	close(fd);
	return (height);
}

char	**make_row(int fd)
{
	char	**array;
	char	*line;

	line = get_next_line(fd);
	array = ft_split(line, ' ');
	free(line);
	return (array);
}

char	***make_string_matrix(char *path, int height)
{
	char	***array;
	int		fd;
	int		y;

	fd = open(path, O_RDONLY);
	array = malloc(sizeof(char **) * height);
	y = -1;
	while (++y < height)
		array[y] = make_row(fd);
	free(get_next_line(fd));
	close(fd);
	return (array);
}

int	parse_map(char *path, t_fdf *data)
{
	char	***string_matrix;
	int		map_check;
	int		width;
	int		height;

	map_check = validate_map(path, data);
	if (!map_check)
		ft_error("invalid map.", __FILE__, __func__, __LINE__);
	height = get_map_height(path);
	width = get_map_width(path);
	string_matrix = make_string_matrix(path, height);
	s_to_point_matrix(data, string_matrix, width, height);
	free_string_matrix(string_matrix, height);
	return (map_check);
}
