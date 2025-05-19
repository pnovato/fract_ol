#include "../include/fractol.h"

static void print_help(void)
{
	ft_printf("Usage:\n");
	ft_printf("  ./fractol mandelbrot\n");
	ft_printf("  ./fractol julia <real> <imag>\n");
	exit(1);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		print_help();
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
	return (0);
}

