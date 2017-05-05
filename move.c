/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 16:20:49 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/02/25 16:21:07 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	move_up(t_env *env)
{
	mlx_clear_window(env->mlx->mlx, env->mlx->window);
	env->fractal->position_y -= (0.1 * WIN_HEIGHT / env->fractal->zoom / 2);
	draw(env);
}

void	move_down(t_env *env)
{
	mlx_clear_window(env->mlx->mlx, env->mlx->window);
	env->fractal->position_y += (0.1 * WIN_HEIGHT / env->fractal->zoom / 2);
	draw(env);
}

void	move_right(t_env *env)
{
	mlx_clear_window(env->mlx->mlx, env->mlx->window);
	env->fractal->position_x += (0.1 * WIN_WIDTH / env->fractal->zoom / 2);
	draw(env);
}

void	move_left(t_env *env)
{
	mlx_clear_window(env->mlx->mlx, env->mlx->window);
	env->fractal->position_x -= (0.1 * WIN_WIDTH / env->fractal->zoom / 2);
	draw(env);
}
