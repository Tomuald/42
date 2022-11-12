#include "includes/cub3d.h"

int destroy_window(t_data *data)
{
  mlx_destroy_window(data->mlx, data->window);
  data->window = NULL;
  exit(0);
  return (0);
}

int convert_to_rgb(char *r, char *g, char *b)
{
  int trgb[4];
  int i;
  
  if (!r | !g | !b)
    return (-1);
  if (!ft_isint(r) || !ft_isint(g) || !ft_isint(b))
    return (-1);
  trgb[0] = 0;
  trgb[1] = ft_atoi(r);
  trgb[2] = ft_atoi(g);
  trgb[3] = ft_atoi(b);
  i = -1;
  while (++i < 4)
    if (trgb[i] > 255 || trgb[i] < 0)
      return (-1);
  return (trgb[0] << 24 | trgb[1] << 16 | trgb[2] << 8 | trgb[3]);
}

void print_structure(t_data *data)
{
  int i;
  int x;
  int y;

  i = -1;
  printf("===\tCub3D\t===\n");
  printf("===\tAssets\t===\n");
  while (++i < 4)
    printf("%d. %s\n", i, data->map->textures[i]);
  printf("\n===\tColors\t===\n");
  printf("F: %d C: %d\n", data->map->fcolor, data->map->ccolor);
  y = 0;
  printf("\n===\tMap\t===\n");
  printf("width: %d, height: %d\n\n", data->map->width, data->map->height);
  while (data->map->map[y])
  {
    x = 0;
    while (data->map->map[y][x])
    {
      printf("%c", data->map->map[y][x]);
      x++;
    }
    printf("\n");
    y++;
  }
  printf("\n===\tPlayer\t===\n");
  printf("(%d, %d), direction: %c\n", data->player->x, data->player->y, data->player->direction);
  printf("\n===================\n");
  return ;
}

char *get_wall(int index)
{
  if (index == 0)
    return ("NO");
  if (index == 1)
    return ("WE");
  if (index == 2)
    return ("SO");
  if (index == 3)
    return ("EA");
  return (NULL);
}
