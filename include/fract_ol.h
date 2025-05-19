#ifndef FRACT_OL_H
# define FRACT_OL_H

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
}	t_vars;


void	init_window(t_vars *vars);

#endif

