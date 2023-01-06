#include "includes/cub3d.h"

int set_player(t_data *data)
{
  int x;
  int y;

  if (!data)
    return (EXIT_FAILURE);
  y = 0;
  while (data->map->map[y])
  {
    x = 0;
    while (data->map->map[y][x])
    {
      if (ft_isinset(data->map->map[y][x], "NWSE"))
      {
	data->player->x = x;
	data->player->y = y;
	data->player->direction = data->map->map[y][x];
      }
      x++;
    }
    y++;
  }
  return (EXIT_SUCCESS);
}

int is_map(char *line)
{
  int i;
  int j;

  if (!line)
    return (EXIT_FAILURE);
  i = 0;
  while (line[i])
  {
    while (line[i] && ft_isspace(line[i]))
      i++;
    j = -1;
    while (++j < 4)
      if (ft_strncmp(&line[i], get_wall(j), 2) == 0)
        return (EXIT_FAILURE);
    if (ft_strncmp(&line[i], "F", 1) == 0)
      return (EXIT_FAILURE);
    else if (ft_strncmp(&line[i], "C", 1) == 0)
      return (EXIT_FAILURE);
    else if (ft_isdigit(line[i]))
      return (EXIT_SUCCESS);
    else
      return (-1);
    if (line[i])
      i++;
  }
  return (EXIT_SUCCESS);
}

char *fill_line(char *line, int longest)
{
  char *filled;
  int diff;
  int i;

  if (!line)
    return (NULL);
  i = 0;
  filled = NULL;
  while (line[i] && i < (int)ft_strlen(line) - 1)
  {
    if (ft_isspace(line[i]))
      filled = ft_add_to_s(filled, '1');
    else
      filled = ft_add_to_s(filled, line[i]);
    i++;
  }
  diff = longest - ft_strlen(filled);
  if (diff > 0)
    while (diff--)
      filled = ft_add_to_s(filled, '1');
  return (filled);
}

int find_longest_line(char **tokens, int *i)
{
  int len;
  int j;

  j = (*i);
  len = ft_strlen(tokens[j]);
  while (tokens[j])
  {
    if ((int) ft_strlen(tokens[j]) > len)
      len = ft_strlen(tokens[j]);
    j++;
  }
  return (len);
}

int calculate_dimensions(char **tokens, int *i, t_data *data)
{
  int height;

  height = *i;
  while (tokens[height])
    height++;
  data->map->height = height - *i;
  data->map->width = find_longest_line(tokens, i) - 1;
  if (data->map->height <= 0 || data->map->width <= 0)
    return (EXIT_FAILURE);
  data->map->size = data->map->height * data->map->width;
  return (EXIT_SUCCESS);
}

int parse_map(char **tokens, int *i, t_data *data)
{
  char *line;
  
  if (!tokens || !data || !i)
    return (EXIT_FAILURE);
  if (calculate_dimensions(tokens, i, data) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  while (tokens[(*i)])
  {
    line = fill_line(tokens[*i], data->map->width);
    data->map->map = ft_add_to_sarray(data->map->map, line, 1);
    (*i)++;
  }
  return (EXIT_SUCCESS);
}

int check_filepath(char *filepath)
{
  int len;

  len = ft_strlen(filepath);
  if (ft_strncmp(&filepath[len - 4], ".cub", 4) != 0)
  {
    ft_printf(STDERR_FILENO, "Error\ncub3d reads .cub maps\n");
    return (EXIT_FAILURE);
  }
  if (access(filepath, R_OK) == -1)
  {
    ft_printf(STDERR_FILENO, "Error\ncannot access() map\n");
    return (EXIT_FAILURE);
  }
  return (EXIT_SUCCESS);
}

char **read_file(char *filepath)
{
  char **array;
  char *line;
  int fd;

  array = NULL;
  if (!filepath)
    return (NULL);
  fd = open(filepath, O_RDONLY);
  if (fd == -1)
    return (NULL);
  line = get_next_line(fd);
  while (line)
  {
    array = ft_add_to_sarray(array, line, 1);
    line = get_next_line(fd);
  }
  close(fd);
  return (array);
}

char **tokenize(char *line)
{
  char **tokens;
  char *token;
  int i;

  if (!line)
    return (NULL);
  i = 0;
  tokens = NULL;
  while (line[i])
  {
    token = NULL;
    while (line[i] && !ft_isspace(line[i]) && !ft_isinset(line[i], ","))
      token = ft_add_to_s(token, line[i++]);
    if (token)
      tokens = ft_add_to_sarray(tokens, token, 1);
    i++;
  }
  return (tokens);
}

int set_tokens(char **tokens, t_data *data)
{
  int i;
  int j;
  int color;

  color = -1;
  if (!tokens || !data)
    return (EXIT_FAILURE);
  i = 0;
  while (tokens[i])
  {
    j = -1;
    while (++j < 4)
      if (ft_strncmp(tokens[i], get_wall(j), 2) == 0)
        data->map->textures[j] = ft_strdup(tokens[(i++) + 1]);
    if ((ft_isinset('F', tokens[i]) || ft_isinset('C', tokens[i])) && ft_strlen(tokens[i]) == 1)
    {
		if (ft_get_array_length(tokens) < 4) {
			data->map->fcolor = -1;
			data->map->ccolor = -1;
			return (EXIT_FAILURE);
		}
      color = convert_to_rgb(tokens[i + 1], tokens[i + 2], tokens[i + 3]);
      if (ft_strncmp(tokens[i], "F", 1) == 0 && color != -1) {
        data->map->fcolor = color;
      }
      if (ft_strncmp(tokens[i], "C", 1) == 0 && color != -1) {
        data->map->ccolor = color;
      }
    }
    i++;
  }
  return (EXIT_SUCCESS);
}

int forge_structure(char **array, t_data *data)
{
  char **tokens;
  int i;

  if (!array || !data)
    return (EXIT_FAILURE);
  i = 0;
  while (array[i])
  {
    if (is_map(array[i]) == EXIT_FAILURE)
    {
      tokens = tokenize(array[i]);
      set_tokens(tokens, data);
      ft_free_carray(tokens);
    }
    else if (is_map(array[i]) == EXIT_SUCCESS)
      parse_map(array, &i, data);
    else
      ft_perror("unknown map setting", __FILE__, __func__, __LINE__);
    if (array[i])
      i++;
  }
  ft_free_carray(array);
  return (EXIT_SUCCESS);
}

int check_axis(t_data *data, int x, int y)
{
  int i;
  int j;
  int axis;

  i = x;
  j = y;
  axis = 0;
  while (x >= 0)
  {
    if (data->map->map[y][x] == '1')
    {
      axis++;
      break ;
    }
    x--;
  }
  x = i;
  y = j;
  while (x < data->map->width)
  {
    if (data->map->map[y][x] == '1')
    {
      axis++;
      break ;
    }
    x++;
  }
  x = i;
  y = j;
  while (y >= 0)
  {
    if (data->map->map[y][x] == '1')
    {
      axis++;
      break ;
    }
    y--;
  }
  x = i;
  y = j;
  while (y < data->map->height)
  {
    if (data->map->map[y][x] == '1')
    {
      axis++;
      break ;
    }
    y++;
  }
  if (axis == 4)
    return (EXIT_SUCCESS);
  return (EXIT_FAILURE);
}

int check_map_integrity(t_data *data)
{
  int x;
  int y;

  y = 0;
  while (y < data->map->height)
  {
    x = 0;
    while (x < data->map->width)
    {
      if (ft_isinset(data->map->map[y][x], "0NWSE"))
	if (check_axis(data, x, y) == EXIT_FAILURE)
	  return (EXIT_FAILURE);
      x++;
    }
    y++;
  }
  return (EXIT_SUCCESS);
}

int validate_map(t_map *map, t_data *data)
{
  int y;
  int x;
  int player;

  player = 0;
  y = -1;
  while (map->map[++y])
  {
    x = -1;
    while (map->map[y][++x])
    {
      if (!ft_isinset(map->map[y][x], "01NWSE"))
	return (EXIT_FAILURE);
      if (ft_isinset(map->map[y][x], "NWSE"))
	player++;
    }
  }
  if (player != 1)
    return (EXIT_FAILURE);
  if (check_map_integrity(data) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int validate_data(t_data *data)
{
  int i;

  i = -1;
  while (++i < 4)
    if (!data->map->textures[i] || access(data->map->textures[i], R_OK) == -1)
      return (EXIT_FAILURE);
  if (!data->map->fcolor || data->map->fcolor == -1)
     return (EXIT_FAILURE);
  if (!data->map->ccolor || data->map->ccolor == -1)
     return (EXIT_FAILURE);
  if (validate_map(data->map, data) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int setup_mlx(t_data *data)
{
  data->mlx = mlx_init();
  data->window = mlx_new_window(data->mlx, 500, 600, "cub3d");
  return (EXIT_SUCCESS);
}

int parser(char *filepath, t_data *data)
{
  char **array;

  if (check_filepath(filepath) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  array = read_file(filepath);
  if (!array)
    return (EXIT_FAILURE);
  if (forge_structure(array, data) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (set_player(data) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (validate_data(data) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  print_structure(data);
  return (EXIT_SUCCESS);
}
