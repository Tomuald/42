/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgarriss <tgarriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 10:05:07 by tgarriss          #+#    #+#             */
/*   Updated: 2022/05/12 12:20:07 by tgarriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// fix this to take into account colors.
t_point	make_point(int x, int y, char *value)
{
	t_point	point;
	char	**array;

	array = ft_split(value, ',');
	point.x = x;
	point.y = y;
	if (!array)
		ft_error("invalid map", __FILE__, __func__, __LINE__);
	point.z = ft_atoi(array[0]);
	point.color = 0xffffff;
	ft_free_carray(array);
	return (point);
}

void	s_to_point_matrix(t_fdf *data, char ***smatrix, int width, int height)
{
	t_point	**matrix;
	int		x;
	int		y;

	matrix = (t_point **) malloc(sizeof(t_point *) * height);
	y = 0;
	while (y < height)
	{
		x = 0;
		matrix[y] = malloc(sizeof(t_point) * width);
		while (x < width)
		{
			matrix[y][x] = make_point(x, y, smatrix[y][x]);
			x++;
		}
		y++;
	}
	data->map = malloc(sizeof(t_map));
	data->map->matrix = matrix;
	data->map->width = width;
	data->map->height = height;
}

void	free_string_matrix(char ***matrix, int height)
{
	int	i;

	i = -1;
	while (++i < height)
		ft_free_carray(matrix[i]);
	free(matrix);
}
