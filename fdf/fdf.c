/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgarriss <tgarriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:40:51 by tgarriss          #+#    #+#             */
/*   Updated: 2022/05/11 15:40:45 by tgarriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Make sure you check for invalid maps properly. If z-values are missing, ...

#include "fdf.h"

static void	free_main(t_fdf *data)
{
	free_map(data->map, data->height);
	mlx_destroy_image(data->mlx, data->img.image);
	free(data->mlx);
}

static void	init_data(t_fdf *data)
{
	data->color_background = 0x000000;
	data->color_line = 0xFFFFFF;
	data->zoom = 2;
	data->z_scale = 1;
	data->offset_x = (WIDTH / 2) - ((data->map->width * data->zoom) / 2);
	data->offset_y = (HEIGHT / 2) - ((data->map->height * data->zoom) / 2);
}

void	display_menu(t_fdf *data)
{
	mlx_string_put(data->mlx, data->window, 5, 20, 0xffffff, \
		"Zoom: Keypad '+' '-'");
	mlx_string_put(data->mlx, data->window, 5, 40, 0xffffff, \
		"Move: Arrows 'Up, Down, Left or Right'");
	mlx_string_put(data->mlx, data->window, 5, 60, 0xffffff, \
		"Z Scale: 'i' 'p'");
}

int	main(int argc, char **argv)
{
	t_fdf	data;

	if (argc != 2)
		ft_error("Usage: ./fdf <path_to_map.fdf>", \
			__FILE__, __func__, __LINE__);
	data.mlx = mlx_init();
	data.w_check = -1;
	parse_map(argv[1], &data);
	init_data(&data);
	data.window = mlx_new_window(data.mlx, WIDTH, HEIGHT, "fdf");
	data.img.image = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.image, &data.img.bpp, \
		&data.img.line_length, &data.img.endian \
	);
	mlx_loop_hook(data.mlx, &render, &data);
	mlx_hook(data.window, 17, 0, close_window, &data);
	mlx_hook(data.window, 2, 0, handle_input, &data);
	mlx_loop(data.mlx);
	free_main(&data);
	return (0);
}
