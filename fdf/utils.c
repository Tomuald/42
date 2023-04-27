/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgarriss <tgarriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:43:58 by tgarriss          #+#    #+#             */
/*   Updated: 2022/05/13 12:33:30 by tgarriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_file(char *path)
{
	int	length;

	length = ft_strlen(path);
	if (ft_strncmp(&path[length - 4], ".fdf", 4) == 0)
		return (1);
	return (0);
}

void	free_map(t_map *map, int height)
{
	int	y;

	y = -1;
	while (++y < height)
		free(map->matrix[y]);
	free(map);
}

float	find_max(int a, int b)
{
	if (ft_absolute(a) > ft_absolute(b))
		return (a);
	return (b);
}

int	count_values(char *line)
{
	char	**array;
	int		values;
	int		i;

	i = 0;
	values = 0;
	array = ft_split(line, ' ');
	while (array[i])
	{
		if (array[i][0] != '\n')
			values++;
		i++;
	}
	ft_free_carray(array);
	return (values);
}

int	validate_map(char *path, t_fdf *data)
{
	char	*line;
	int		values;
	int		valid;
	int		fd;

	fd = open(path, O_RDONLY);
	valid = 1;
	line = get_next_line(fd);
	while (line)
	{
		values = count_values(line);
		if (data->w_check == -1)
			data->w_check = values;
		if (data->w_check != values)
			valid = 0;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (valid);
}
