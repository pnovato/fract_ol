#include "../include/fractol.h"

void	put_pixel(t_vars *vars, int x, int y, int color)
{
	char	*dst;
	int		offset;
	int		bytes_per_pixel;

	bytes_per_pixel = vars->bpp / 8;
	offset = y * vars->line_len + x * bytes_per_pixel;
	dst = vars->img_addr + offset;
	*(unsigned int *)dst = color;
}

int	choose_color(int iter)
{
	int	color;

	if (iter >= 100)
		color = 0x000000;
	else
		color = iter * 0x001111;
	return (color);
}

