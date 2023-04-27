/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgarriss <tgarriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 12:38:47 by tgarriss          #+#    #+#             */
/*   Updated: 2022/05/12 15:29:07 by tgarriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx/mlx.h"
# include "libft/includes/libft.h"
# include <math.h>

# define WIDTH 1920
# define HEIGHT 1080

/*--- structures ---*/
// ->addr is the array of chars that contain pixel info
typedef struct s_img
{
	void	*image;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_point;

typedef struct s_map
{
	t_point	**matrix;
	int		width;
	int		height;
}	t_map;

typedef struct s_fdf
{
	t_map				*map;
	void				*mlx;
	void				*window;
	char				*path;
	t_img				img;
	unsigned int		color_background;
	unsigned int		color_line;
	int					height;
	int					width;
	int					zoom;
	int					offset_x;
	int					offset_y;
	int					dx;
	int					dy;
	int					x_inc;
	int					y_inc;
	int					z_scale;
	int					w_check;
}	t_fdf;

/*--- fdf.c ---*/
void	display_menu(t_fdf *data);

/*--- maps.c ---*/
int		parse_map(char *path, t_fdf *data);

/*--- render.c ---*/
int		render(t_fdf *data);
void	render_pixel(t_img *img, int x, int y, int color);

/*--- utils.c ---*/
float	find_max(int a, int b);
void	free_map(t_map *map, int height);
int		check_file(char *path);
int		validate_map(char *path, t_fdf *data);
int		count_values(char *line);

/*--- bresenham.c ---*/
void	bresenham(t_point *p1, t_point *p2, t_fdf *data);

/*--- transform.c ---*/
void	transform_points(t_point *p1, t_point *p2, t_fdf *data);

/*--- keypress.c ---*/
int		close_window(t_fdf *data);
int		handle_input(int keysym, t_fdf *data);

/*--- matrix.c ---*/
void	point_by_matrix(t_point *p, int **matrix);
void	free_string_matrix(char ***matrix, int height);
void	s_to_point_matrix(t_fdf *data, char ***smatrix, int width, int height);
t_point	make_point(int x, int y, char *value);

#endif
