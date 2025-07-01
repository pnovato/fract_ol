#include "../include/fractol.h"

static int	compute_julia(double x0, double y0, t_vars *vars)
{
	int		iter;
	double	x;
	double	y;
	double	tmp;

	x = x0;
	y = y0;
	iter = 0;
	while (x * x + y * y <= 4 && iter < vars->max_iter)
	{
		tmp = x * x - y * y + vars->c_re;
		y = 2 * x * y + vars->c_im;
		x = tmp;
		iter++;
	}
	return (iter);
}

void	draw_julia(t_vars *vars)
{
	int		x;
	int		y;
	double	re;
	double	im;
	int		iter;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			re = vars->min_re + x * (vars->max_re - vars->min_re) / WIDTH;
			im = vars->max_im - y * (vars->max_im - vars->min_im) / HEIGHT;
			iter = compute_julia(re, im, vars);
			put_color(vars, x, y, iter);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->img_ptr, 0, 0);
}

