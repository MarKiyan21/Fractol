/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 15:18:23 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/03/01 14:44:19 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init_fractal(int fractal_type, t_env *env)
{
	t_fractal	*fractal;

	fractal = (t_fractal*)malloc(sizeof(t_fractal));
	if (fractal_type == 1)
		init_mandelbrot(fractal);
	else if (fractal_type == 2)
		init_julia(fractal);
	else if (fractal_type == 3)
		init_flower_power(fractal);
	else if (fractal_type == 4)
		init_the_batman(fractal);
	env->fractal = fractal;
}

static void	init_mlx(t_env *env)
{
	t_mlx	*mlx;

	mlx = (t_mlx*)malloc(sizeof(t_mlx));
	mlx->mlx = mlx_init();
	mlx->window = mlx_new_window(mlx->mlx, WIN_WIDTH, WIN_HEIGHT, "Fractol");
	env->flag = 1;
	env->mlx = mlx;
}

t_env		*init(int fractal_type)
{
	t_env	*env;

	env = (t_env*)malloc(sizeof(t_env));
	init_fractal(fractal_type, env);
	init_mlx(env);
	return (env);
}
