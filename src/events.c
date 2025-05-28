#include "../include/fractol.h"
#include <stdio.h>
/*
static double	map_mouse_to_re(t_vars *vars, int x)
{
	return (vars->min_re + x * (vars->max_re - vars->min_re) / WIDTH);
}

static double	map_mouse_to_im(t_vars *vars, int y)
{
	return (vars->min_im  + y * (vars->max_im - vars->min_im) / HEIGHT);
}
*/

void	apply_zoom(t_vars *vars, double zoom, int x, int y)
{
	double	mouse_re;
	double	mouse_im;
	double	range_re;
	double	range_im;

	mouse_re = vars->min_re + x * (vars->max_re - vars->min_re) / WIDTH;
	mouse_im = vars->min_im + y * (vars->max_im - vars->min_im) / HEIGHT;
	range_re = vars->max_re - vars->min_re;
	range_im = vars->max_im - vars->min_im;
	vars->min_re = mouse_re - (range_re * zoom / 2);
	vars->max_re = mouse_re + (range_re * zoom / 2);
	vars->min_im = mouse_im - (range_im * zoom / 2);
	vars->max_im = mouse_im + (range_im * zoom / 2);
	draw_mandelbrot(vars);
}

int	handle_mouse(int button, int x, int y, t_vars *vars)
{
	printf("Mouse: button=%d, x=%d, y=%d\n", button, x, y);

	if (button == 61 || button == 65451) // '=' ou '+ numérico'
		apply_zoom(vars, 0.9, WIDTH / 2, HEIGHT / 2);
	if (button == 45 || button == 65453) // '-' ou '- numérico'
		apply_zoom(vars, 1.1, WIDTH / 2, HEIGHT / 2);
	return (0);
}

int	zoom_loop(t_vars *vars)
{
	if (vars->zoom_in)
		apply_zoom(vars, 0.95, WIDTH / 2, HEIGHT / 2);
	if (vars->zoom_out)
		apply_zoom(vars, 1.05, WIDTH / 2, HEIGHT / 2);
	return (0);
}

void	move_view(t_vars *vars, double dx, double dy)
{
	double	range_re;
	double	range_im;

	range_re = vars->max_re - vars->min_re;
	range_im = vars->max_im - vars->min_im;
	vars->min_re += dx * range_re;
	vars->max_re += dx * range_re;
	vars->min_im += dy * range_im;
	vars->max_im += dy * range_im;
	draw_mandelbrot(vars);
}

