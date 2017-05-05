/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 12:12:23 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/03/01 12:57:04 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_mandelbrot(t_fractal *fractal)
{
	fractal->type = 1;
	fractal->position_x = -2.6;
	fractal->position_y = -1.2;
	fractal->zoom = 300;
	fractal->color_base = 0x69A598;
	fractal->max_iterations = MAX_ITER_BASE;
}

void	init_julia(t_fractal *fractal)
{
	fractal->type = 2;
	fractal->position_x = -2.8;
	fractal->position_y = -1.9;
	fractal->zoom = 175;
	fractal->color_base = 0x030000;
	fractal->max_iterations = MAX_ITER_BASE;
	fractal->cx = 0;
	fractal->cy = 0;
}

void	init_flower_power(t_fractal *fractal)
{
	fractal->type = 3;
	fractal->position_x = -2.8;
	fractal->position_y = -1.9;
	fractal->zoom = 175;
	fractal->color_base = 0x835E9C;
	fractal->max_iterations = MAX_ITER_BASE;
	fractal->cx = 0;
	fractal->cy = 0;
}

void	init_the_batman(t_fractal *fractal)
{
	fractal->type = 4;
	fractal->position_x = -2.8;
	fractal->position_y = -1.9;
	fractal->zoom = 175;
	fractal->color_base = 0xEFEFF1;
	fractal->max_iterations = MAX_ITER_BASE;
	fractal->cx = 0;
	fractal->cy = 0;
}
