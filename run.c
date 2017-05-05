/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 16:21:16 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/03/01 15:09:53 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	mouse_hook(int button, int x, int y, t_env *env)
{
	if (button == 1)
		enhance(env);
	else if (button == 2)
		diminish(env);
	else if (button == 4)
		zoom_in(x, y, env);
	else if (button == 5)
		zoom_out(x, y, env);
	return (0);
}

static int	key_hook(int keycode, t_env *env)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == 15)
		stop(env);
	else if (keycode == 125)
		move_up(env);
	else if (keycode == 126)
		move_down(env);
	else if (keycode == 123)
		move_right(env);
	else if (keycode == 124)
		move_left(env);
	else if (keycode == 8)
		rotate_color(env);
	return (0);
}

static int	mouse_move(int x, int y, t_env *env)
{
	static int	saved_x = WIN_WIDTH / 2;
	static int	saved_y = WIN_HEIGHT / 2;

	if ((x != saved_x || y != saved_y) && x > 0 && y > 0 &&
	x < WIN_WIDTH && y < WIN_HEIGHT && env->flag == 1)
	{
		if (x < saved_x)
			env->fractal->cx -= 0.01 * (saved_x - x);
		else if (x > saved_x)
			env->fractal->cx += 0.01 * (x - saved_x);
		if (y < saved_y)
			env->fractal->cy -= 0.02 * (saved_y - y);
		else if (y > saved_y)
			env->fractal->cy += 0.02 * (y - saved_y);
		if (x != saved_x)
			saved_x = x;
		if (y != saved_y)
			saved_y = y;
		mlx_clear_window(env->mlx->mlx, env->mlx->window);
		draw(env);
	}
	return (0);
}

void		run(t_env *env)
{
	mlx_expose_hook(env->mlx->window, draw, env);
	mlx_mouse_hook(env->mlx->window, mouse_hook, env);
	mlx_hook(env->mlx->window, 2, 3, key_hook, env);
	if (env->fractal->type == 2 || env->fractal->type == 3
		|| env->fractal->type == 4)
		mlx_hook(env->mlx->window, 6, 0, mouse_move, env);
	mlx_loop(env->mlx->mlx);
}
