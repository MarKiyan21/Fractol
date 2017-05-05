/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 12:06:53 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/03/01 12:47:30 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	stop(t_env *env)
{
	if (env->flag == 1)
		env->flag = 0;
	else
		env->flag = 1;
}

void	rotate_color(t_env *env)
{
	mlx_clear_window(env->mlx->mlx, env->mlx->window);
	env->fractal->color_base += 255;
	draw(env);
}
