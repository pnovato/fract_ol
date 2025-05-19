#include "../include/fract_ol.h"

void	close_window(t_vars *vars)
{
	if (vars->img_ptr)
		mlx_destroy_image(vars->mlx_ptr, vars->img_ptr);
	if (vars->win_ptr)
		mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
	if (vars->mlx_ptr)
		free(vars->mlx_ptr);
	exit(0);
}

int	handle_key(int keycode, t_vars *vars)
{
	if (keycode == 65307) // ESC
		close_window(vars);
	return (0);
}

int	handle_close(t_vars *vars)
{
	close_window(vars);
	return (0);
}

void	init_window(t_vars *vars)
{
	vars->mlx_ptr = mlx_init();
	if (!vars->mlx_ptr)
		exit(1);

	vars->win_ptr = mlx_new_window(vars->mlx_ptr, WIDTH, HEIGHT, "fract-ol");
	if (!vars->win_ptr)
	{
		free(vars->mlx_ptr);
		exit(1);
	}

	vars->img_ptr = mlx_new_image(vars->mlx_ptr, WIDTH, HEIGHT);
	if (!vars->img_ptr)
		close_window(vars);

	vars->img_addr = mlx_get_data_addr(vars->img_ptr,
			&vars->bpp, &vars->line_len, &vars->endian);

	mlx_hook(vars->win_ptr, 17, 0, handle_close, vars);
	mlx_key_hook(vars->win_ptr, handle_key, vars);
}

