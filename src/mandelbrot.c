#include "../include/fractol.h"

static int	mandelbrot_iter(double cr, double ci)
{
	double	zr;
	double	zi;
	double	zr2;
	double	zi2;
	int		i;
	int		max_iter;

	zr = 0.0;
	zi = 0.0;
	i = 0;
	max_iter = 100;
	while (i < max_iter)
	{
		zr2 = zr * zr;
		zi2 = zi * zi;
		if (zr2 + zi2 > 4.0)
			break ;
		zi = 2 * zr * zi + ci;
		zr = zr2 - zi2 + cr;
		i++;
	}
	return (i);
}

void	draw_mandelbrot(t_vars *vars)
{
	int		x;
	int		y;
	double	cr;
	double	ci;
	int		iter;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			cr = vars->min_re + x * (vars->max_re - vars->min_re) / WIDTH;
			ci = vars->min_im + y * (vars->max_im - vars->min_im) / HEIGHT;
			iter = mandelbrot_iter(cr, ci);
			put_pixel(vars, x, y, choose_color(iter));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(vars->mlx_ptr,
		vars->win_ptr, vars->img_ptr, 0, 0);
}

