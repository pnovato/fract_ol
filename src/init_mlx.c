#include "../include/fractol.h"
#include <stdio.h>

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
	printf("button = %d\n", keycode);
	if (keycode == 65307) // ESC
		close_window(vars);
	else if (keycode == 65451 || keycode == 43) // '+' do numérico ou do normal
		apply_zoom(vars, 0.9, WIDTH / 2, HEIGHT / 2);
	else if (keycode == 65453 || keycode == 45) // '-' do numérico ou do normal
		apply_zoom(vars, 1.1, WIDTH / 2, HEIGHT / 2);
	return (0);
}

void	init_fractal_limits(t_vars *vars)
{
	vars->min_re = -2.0;
	vars->max_re = 2.0;
	vars->min_im = -2.0;
	vars->max_im = 2.0;
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
	vars->win_ptr = mlx_new_window(
			vars->mlx_ptr, WIDTH, HEIGHT, "fractol");
	if (!vars->win_ptr)
		exit(1);
	vars->img_ptr = mlx_new_image(vars->mlx_ptr, WIDTH, HEIGHT);
	if (!vars->img_ptr)
		exit(1);
	vars->img_addr = mlx_get_data_addr(
			vars->img_ptr, &vars->bpp, &vars->line_len, &vars->endian);
	init_fractal_limits(vars);
//	mlx_hook(vars->win_ptr, 17, 0, close_window, vars);
//	mlx_hook(vars->win_ptr, 4, 0, handle_mouse, vars);
//	mlx_loop_hook(vars->mlx_ptr, test_loop_hook, vars);
	mlx_key_hook(vars->win_ptr, handle_key, vars);
}
