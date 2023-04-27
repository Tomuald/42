/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgarriss <tgarriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 12:50:21 by tgarriss          #+#    #+#             */
/*   Updated: 2022/05/09 10:20:32 by tgarriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_window(t_fdf *data)
{
	mlx_destroy_window(data->mlx, data->window);
	data->window = NULL;
	exit(0);
	return (0);
}

static void	destroy_window(t_fdf *data)
{
	mlx_destroy_window(data->mlx, data->window);
	data->window = NULL;
	exit(0);
}

int	handle_input(int keysym, t_fdf *data)
{
	if (keysym == 53)
		destroy_window(data);
	if (keysym == 78)
	{
		data->zoom -= 5;
		if (data->zoom < 2)
			data->zoom = 2;
	}
	if (keysym == 69)
	{
		data->zoom += 5;
	}
	if (keysym == 124)
		data->offset_x += (data->zoom * data->map->width) / 25;
	if (keysym == 123)
		data->offset_x -= (data->zoom * data->map->width) / 25;
	if (keysym == 126)
		data->offset_y -= (data->zoom * data->map->height) / 25;
	if (keysym == 125)
		data->offset_y += (data->zoom * data->map->height) / 25;
	if (keysym == 34)
		data->z_scale += 1;
	if (keysym == 35)
		data->z_scale += -1;
	return (0);
}
