#include "../include/fract_ol.h"

static void	print_help(void)
{
	ft_printf("Usage:\n");
	ft_printf("  ./fract_ol mandelbrot\n");
	ft_printf("  ./fract_ol julia <real> <imag>\n");
	exit(1);
}

int	main(int argc, char **argv)
{
	t_vars	vars;
	if (argc < 2)
		print_help();
	init_window(&vars);
	if (!ft_strncmp(argv[1], "mandelbrot", 11))
		ft_printf("Renderizando Mandelbrot...\n");
	else if (!ft_strncmp(argv[1], "julia", 6))
	{
		if (argc != 4)
			print_help();
		ft_printf("Renderizando Julia com c = %s + %si\n", argv[2], argv[3]);
	}
	else
		print_help();
	mlx_loop(vars.mlx_ptr);
	return (0);
}

