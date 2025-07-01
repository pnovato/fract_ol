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

void    put_color(t_vars *vars, int x, int y, int iter)
{
    int red, green, blue;
    int color;
    int offset;

    if (iter == vars->max_iter)
        color = 0x000000;
    else
    {
        red = (iter * 5) % 256;
        green = (iter * 3) % 256;
        blue = (iter * 9) % 256;
        color = (red << 16) | (green << 8) | blue;
    }
    offset = (y * vars->line_len) + (x * (vars->bpp / 8));
    vars->img_addr[offset] = color & 0xFF;
    vars->img_addr[offset + 1] = (color >> 8) & 0xFF;
    vars->img_addr[offset + 2] = (color >> 16) & 0xFF;
}


