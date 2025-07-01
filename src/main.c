#include "../include/fractol.h"

static void	print_help(void)
{
	ft_printf("Usage:\n");
	ft_printf("  ./fractol mandelbrot\n");
	ft_printf("  ./fractol julia <real> <imag>\n");
	exit(1);
}

static double	parse_decimal(const char *str)
{
	double	result;
	double	divisor;

	result = 0.0;
	divisor = 10.0;
	while (*str >= '0' && *str <= '9')
	{
		result += (*str - '0') / divisor;
		divisor *= 10;
		str++;
	}
	return (result);
}

static double	ft_atof(const char *str)
{
	double	result;
	int		sign;

	result = 0.0;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		result = result * 10 + (*str++ - '0');
	if (*str == '.')
		result += parse_decimal(str + 1);
	return (result * sign);
}

void init_mandelbrot(t_vars *vars)
{
	vars->fractal_type = 1;
	vars->max_iter = 100;
	vars->min_re = -2.0;
	vars->max_re = 1.0;
	vars->min_im = -1.5;
	vars->max_im = 1.5;
}

void init_julia(t_vars *vars, char **argv)
{
	vars->fractal_type = 2;
	vars->max_iter = 100;
	vars->min_re = -1.5;
	vars->max_re = 1.5;
	vars->min_im = -1.5;
	vars->max_im = 1.5;
	vars->c_re = ft_atof(argv[2]);
	vars->c_im = ft_atof(argv[3]);
}

int	main(int argc, char **argv)
{
	t_vars	vars;
	if (argc < 2)
		print_help();
	init_window(&vars);
	if (!ft_strncmp(argv[1], "mandelbrot", 11))
	{
		ft_printf("Renderizando Mandelbrot...\n");
		init_mandelbrot(&vars);
		draw_mandelbrot(&vars);
	}
	else if (!ft_strncmp(argv[1], "julia", 6) && argc == 4)
	{
		ft_printf("Renderizando Julia...\n");
		init_julia(&vars, argv);
		draw_julia(&vars);
	}
	else
		print_help();
	mlx_loop(vars.mlx_ptr);
	return (0);
}

