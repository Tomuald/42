#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/includes/libft.h"
//# include "../mlx-linux/mlx.h"
# include "../mlx-mac/mlx.h"

/*--- Structures ---*/
typedef struct s_point
{
  int x;
  int y;
  char value;
} t_point;

typedef struct s_map
{
  char **textures;
  char **map;
  int ccolor;
  int fcolor;
  int height;
  int width;
  int size;
} t_map;

typedef struct s_player
{
  char direction;
  int x;
  int y;
} t_player;

typedef struct	s_data
{
  void	*mlx;
  void	*window;
  t_map	*map;
  t_player	*player;
}	t_data;

/*--- Functions ---*/

/*--- utils.c ---*/
int destroy_window(t_data *data);
int handle_keypress(int keysym, t_data *data);
int convert_to_rgb(char *r, char *g, char *b);
void print_structure(t_data *data);
char *get_wall(int index);

/*--- parse.c ---*/
int parser(char *filepath, t_data *data);

/*--- UNSORTED ---*/
int forge_structure(char **array, t_data *data);
char **tokenize(char *line);
int set_tokens(char **tokens, t_data *data);
int parse_map(char **tokens, int *i, t_data *data);
int calculate_dimensions(char **tokens, int *i, t_data *data);
int check_map_integrity(t_data *data);
int setup_mlx(t_data *data);

#endif
