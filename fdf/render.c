/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgarriss <tgarriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:42:09 by tgarriss          #+#    #+#             */
/*   Updated: 2022/05/09 10:21:31 by tgarriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// this calculation gets me the pointer (img-addr)[calculation] or
// (pointer) + (calculation)
// row_pos * linelength + (col_pos * bytes)
// then, having its address, I can set its color.
void	render_pixel(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(int *)pixel = color;
}

static void	render_background(t_img *img, int color)
{
	int	y;
	int	x;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			render_pixel(img, x, y, color);
	}
}

static void	render_map_2(t_fdf *data, int x, int y)
{
	t_point	p1;
	t_point	p2;

	if (x < data->map->width - 1)
	{
		p1 = data->map->matrix[y][x];
		p2 = data->map->matrix[y][x + 1];
		transform_points(&p1, &p2, data);
		bresenham(&p1, &p2, data);
	}
	if (y < data->map->height - 1)
	{
		p1 = data->map->matrix[y][x];
		p2 = data->map->matrix[y + 1][x];
		transform_points(&p1, &p2, data);
		bresenham(&p1, &p2, data);
	}
}

void	render_map(t_fdf *data)
{
	int		x;
	int		y;

	y = -1;
	while (++y < data->map->height)
	{
		x = -1;
		while (++x < data->map->width)
		{
			render_map_2(data, x, y);
		}
	}
}

int	render(t_fdf *data)
{
	if (!data->window)
		return (1);
	render_background(&data->img, 0x000000);
	render_map(data);
	mlx_put_image_to_window(data->mlx, data->window, data->img.image, 0, 0);
	display_menu(data);
	return (0);
}
