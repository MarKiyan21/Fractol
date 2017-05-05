/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 16:44:12 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/03/01 14:44:24 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <math.h>
# include <complex.h>
# include "libft/libft.h"
# include "mlx.h"

# define WIN_WIDTH 1000
# define WIN_HEIGHT 700

# define MAX_ITER_BASE 50

typedef _Complex double	t_complex;

typedef struct	s_fractal
{
	int			type;
	double		position_x;
	double		position_y;
	double		cx;
	double		cy;
	double		zoom;
	int			color;
	int			color_base;
	int			max_iterations;
	t_complex	z;
}				t_fractal;

typedef struct	s_mlx
{
	void		*mlx;
	void		*window;
	void		*image;
	char		*data;
	int			bpp;
	int			size_line;
	int			endian;
}				t_mlx;

typedef struct	s_env
{
	t_fractal	*fractal;
	t_mlx		*mlx;
	int			flag;
}				t_env;

int				main(int ac, char **av);
void			validate_num_argc(int ac);
int				choose(char *fractal);
t_env			*init(int fractal_type);
void			run(t_env *env);
int				get_iterations(int x, int y, t_env *env);
int				draw(t_env *env);
void			move_up(t_env *env);
void			move_down(t_env *env);
void			move_right(t_env *env);
void			move_left(t_env *env);
void			zoom_in(int x, int y, t_env *env);
void			zoom_out(int x, int y, t_env *env);
void			rotate_color(t_env *env);
void			init_mandelbrot(t_fractal *fractal);
void			init_julia(t_fractal *fractal);
void			init_flower_power(t_fractal *fractal);
void			init_the_batman(t_fractal *fractal);
void			enhance(t_env *env);
void			diminish(t_env *env);
void			stop(t_env *env);

#endif
