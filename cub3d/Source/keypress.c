#include "includes/cub3d.h"

int handle_keypress(int keysym, t_data *data)
{
  // deal with ESC key
  if (keysym == 53)
    destroy_window(data);
  else
    ft_printf(STDERR_FILENO, "%d\n", keysym);
  return (0);
}
