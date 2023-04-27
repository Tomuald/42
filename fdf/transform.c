/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgarriss <tgarriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:08:08 by tgarriss          #+#    #+#             */
/*   Updated: 2022/05/09 10:59:35 by tgarriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	set_zoom(t_point *p1, t_point *p2, t_fdf *data)
{
	p1->x *= data->zoom;
	p1->y *= data->zoom;
	p2->x *= data->zoom;
	p2->y *= data->zoom;
}

static void	set_isometric(t_point *p)
{
	int	previous_x;
	int	previous_y;

	previous_x = p->x;
	previous_y = p->y;
	p->x = (previous_x - previous_y) * cos(0.56373398);
	p->y = -p->z + (previous_x + previous_y) * sin(0.56373398);
}

static void	set_offset(t_point *p1, t_point *p2, t_fdf *data)
{
	p1->x += data->offset_x;
	p2->x += data->offset_x;
	p1->y += data->offset_y;
	p2->y += data->offset_y;
}

static void	set_z_scale(t_point *p1, t_point *p2, t_fdf *data)
{
	p1->z *= data->z_scale;
	p2->z *= data->z_scale;
}

void	transform_points(t_point *p1, t_point *p2, t_fdf *data)
{
	set_zoom(p1, p2, data);
	set_z_scale(p1, p2, data);
	set_isometric(p1);
	set_isometric(p2);
	set_offset(p1, p2, data);
}
