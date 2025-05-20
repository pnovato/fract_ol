#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <mlx.h>
# include "../libft/libft.h"

# define WIDTH 800
# define HEIGHT 800

typedef struct s_vars
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*img_addr;
	int		bpp;
	int		line_len;
	int		endian;

	double	min_re;
	double	max_re;
	double	min_im;
	double	max_im;
}	t_vars;


// init_mlx.c
void	init_window(t_vars *vars);
void	close_window(t_vars *vars);

// events.c
int		handle_mouse(int button, int x, int y, t_vars *vars);
int	test_loop_hook(t_vars *vars);
void	apply_zoom(t_vars *vars, double zoom, int x, int y);

// mandelbrot.c
void	draw_mandelbrot(t_vars *vars);

// draw_utils.c
void	put_pixel(t_vars *vars, int x, int y, int color);
int		choose_color(int iter);


#endif

