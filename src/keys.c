#include "../include/fractol.h"

int	key_press(int keycode, t_vars *vars)
{
	if (keycode == 65451 || keycode == 43)
		vars->zoom_in = 1;
	else if (keycode == 65453 || keycode == 45)
		vars->zoom_out = 1;
	else if (keycode == 65307)
		close_window(vars);
	else if (keycode == 65361)
		move_view(vars, -0.1, 0);
	else if (keycode == 65362)
		move_view(vars, 0, -0.1);
	else if (keycode == 65363)
		move_view(vars, 0.1, 0);
	else if (keycode == 65364)
		move_view(vars, 0, 0.1);
	return (0);
}

int	key_release(int keycode, t_vars *vars)
{
	if (keycode == 65451 || keycode == 43)
		vars->zoom_in = 0;
	else if (keycode == 65453 || keycode == 45)
		vars->zoom_out = 0;
	return (0);
}

