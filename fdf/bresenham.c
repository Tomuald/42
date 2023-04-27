/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgarriss <tgarriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:40:25 by tgarriss          #+#    #+#             */
/*   Updated: 2022/05/05 12:30:39 by tgarriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_matrix(int **matrix, int y)
{
	int	i;

	i = 0;
	while (i < y)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

// m < 1
static void	bresenham_x_increment(t_point *p1, t_point *p2, t_fdf *data)
{
	int	p;
	int	x;
	int	y;

	x = p1->x;
	y = p1->y;
	p = 2 * ft_absolute(data->dy) - ft_absolute(data->dx);
	while (x != p2->x)
	{
		if (x < WIDTH && y < HEIGHT && x > 0 && y > 0)
			render_pixel(&data->img, x, y, data->color_line);
		x += data->x_inc;
		if (p < 0)
			p = p + 2 * ft_absolute(data->dy);
		else
		{
			p = p + 2 * ft_absolute(data->dy) - 2 * ft_absolute(data->dx);
			y += data->y_inc;
		}
	}
}

// m > 1
static void	bresenham_y_increment(t_point *p1, t_point *p2, t_fdf *data)
{
	int	p;
	int	x;
	int	y;

	x = p1->x;
	y = p1->y;
	p = 2 * ft_absolute(data->dx) - ft_absolute(data->dy);
	while (y != p2->y)
	{
		if (x < WIDTH && y < HEIGHT && x > 0 && y > 0)
			render_pixel(&data->img, x, y, data->color_line);
		y += data->y_inc;
		if (p > 0)
		{
			x += data->x_inc;
			p = p + 2 * ft_absolute(data->dx) - 2 * ft_absolute(data->dy);
		}
		else
			p = p + 2 * ft_absolute(data->dx);
	}
}

void	bresenham(t_point *p1, t_point *p2, t_fdf *data)
{
	data->dx = p2->x - p1->x;
	data->dy = p2->y - p1->y;
	data->x_inc = 1;
	data->y_inc = 1;
	if (p1->z || p2->z)
		data->color_line = 0xE80C0C;
	else
		data->color_line = 0xFFFFFF;
	if (data->dx < 0)
		data->x_inc = -1;
	if (data->dy < 0)
		data->y_inc = -1;
	if (abs(data->dx) >= abs(data->dy))
		bresenham_x_increment(p1, p2, data);
	else
		bresenham_y_increment(p1, p2, data);
}
