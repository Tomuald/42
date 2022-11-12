#include "includes/cub3d.h"

t_data *init_struct(void)
{
  t_data *data;

  data = ft_calloc(1, sizeof(t_data));
  data->map = ft_calloc(1, sizeof(t_map));
  data->map->map = NULL;
  data->map->textures = ft_calloc(4, sizeof(char *));
  data->player = ft_calloc(1, sizeof(t_player));
  if (setup_mlx(data) == EXIT_FAILURE)
    return (NULL);
  return (data);
}

void memclean(t_data *data)
{
  int i;

  if (!data)
    return ;
  i = -1;
  while (++i < 4)
	 free(data->map->textures[i]);
  free(data->map->textures);
  if (data->map->map)
    ft_free_carray(data->map->map);
  free(data->map);
  free(data->player);
  destroy_window(data);
  free(data->mlx);
  free(data);
}

int main(int argc, char **argv)
{
  t_data	*data;
  
  if (argc != 2)
    ft_error("Error\nusage: './cub3d <path.cub>'", __FILE__, __func__, __LINE__);
  data = init_struct();
  if (!data)
  {
    ft_printf(STDERR_FILENO, "Error\ninitialization failed.\n");
    return (-1);
  }
  if (parser(argv[1], data) == EXIT_FAILURE)
  {
    ft_printf(STDERR_FILENO, "Error\nInvalid map.\n");
    memclean(data);
    return (EXIT_FAILURE);
  }
  mlx_hook(data->window, 17, 0, destroy_window, data);
  mlx_hook(data->window, 2, 0, handle_keypress, data);
  mlx_loop(data->mlx);
  memclean(data);
  return (EXIT_SUCCESS);
}
