/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 13:44:40 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/03/01 15:08:22 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_in(int x, int y, t_env *env)
{
	double	offset_x;
	double	offset_y;

	mlx_clear_window(env->mlx->mlx, env->mlx->window);
	offset_x = x / env->fractal->zoom + env->fractal->position_x;
	offset_y = y / env->fractal->zoom + env->fractal->position_y;
	env->fractal->zoom *= 1.015;
	env->fractal->position_x = offset_x - WIN_WIDTH / env->fractal->zoom / 2;
	env->fractal->position_y = offset_y - WIN_HEIGHT / env->fractal->zoom / 2;
	draw(env);
}

void	zoom_out(int x, int y, t_env *env)
{
	double	offset_x;
	double	offset_y;

	mlx_clear_window(env->mlx->mlx, env->mlx->window);
	offset_x = x / env->fractal->zoom + env->fractal->position_x;
	offset_y = y / env->fractal->zoom + env->fractal->position_y;
	env->fractal->zoom /= 1.015;
	env->fractal->position_x = offset_x - WIN_WIDTH / env->fractal->zoom / 2;
	env->fractal->position_y = offset_y - WIN_HEIGHT / env->fractal->zoom / 2;
	draw(env);
}
