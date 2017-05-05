/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enhance.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 12:49:45 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/03/01 12:39:12 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	enhance(t_env *env)
{
	mlx_clear_window(env->mlx->mlx, env->mlx->window);
	env->fractal->max_iterations += 5;
	draw(env);
}

void	diminish(t_env *env)
{
	mlx_clear_window(env->mlx->mlx, env->mlx->window);
	env->fractal->max_iterations -= 5;
	draw(env);
}
