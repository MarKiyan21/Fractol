/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_iterations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 16:19:39 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/02/27 18:17:18 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_complex	get_z(double x, double y, t_env *env)
{
	double	initial_x;
	double	initial_y;

	if (env->fractal->type == 1)
		return (0);
	else
	{
		initial_x = x / env->fractal->zoom + env->fractal->position_x;
		initial_y = y / env->fractal->zoom + env->fractal->position_y;
	}
	if (env->fractal->type == 4)
		return (fabs(initial_x) + initial_y * _Complex_I);
	else
		return (initial_x + initial_y * _Complex_I);
}

static t_complex	get_c(double x, double y, t_env *env)
{
	if (env->fractal->type == 1)
	{
		env->fractal->cx = x / env->fractal->zoom + env->fractal->position_x;
		env->fractal->cy = y / env->fractal->zoom + env->fractal->position_y;
	}
	return (env->fractal->cx + env->fractal->cy * _Complex_I);
}

static int			is_point_in_rad(t_complex z)
{
	return (creal(z) * creal(z) + cimag(z) * cimag(z) < 4);
}

int					get_iterations(int x, int y, t_env *env)
{
	int			i;
	t_complex	c;

	i = 0;
	env->fractal->z = get_z(x, y, env);
	c = get_c(x, y, env);
	while (is_point_in_rad(env->fractal->z) && i < env->fractal->max_iterations)
	{
		if (env->fractal->type == 3)
			env->fractal->z = cpow(env->fractal->z, 5) + c;
		else
			env->fractal->z = env->fractal->z * env->fractal->z + c;
		i++;
	}
	return (i);
}
