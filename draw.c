/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 15:20:21 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/02/27 18:02:43 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		get_color(int i, t_env *env)
{
	if (i == env->fractal->max_iterations)
		return (0x000000);
	else
		return (abs(env->fractal->color_base) * (i * 255 / MAX_ITER_BASE));
}

static void		put_pixel_on_image(int x, int y, t_env *env)
{
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;

	b = (env->fractal->color) >> 16;
	g = (env->fractal->color) >> 8;
	r = (env->fractal->color);
	env->mlx->data[y * env->mlx->size_line + x * env->mlx->bpp / 8] = r;
	env->mlx->data[y * env->mlx->size_line + x * env->mlx->bpp / 8 + 1] = g;
	env->mlx->data[y * env->mlx->size_line + x * env->mlx->bpp / 8 + 2] = b;
}

int				draw(t_env *env)
{
	int		i;
	t_mlx	*mlx;
	double	x;
	double	y;

	mlx = env->mlx;
	mlx->image = mlx_new_image(mlx->mlx, WIN_WIDTH, WIN_HEIGHT);
	mlx->data = mlx_get_data_addr(mlx->image, &mlx->bpp, &mlx->size_line,\
	&mlx->endian);
	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			i = get_iterations(x, y, env);
			env->fractal->color = get_color(i, env);
			put_pixel_on_image(x, y, env);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->image, 0, 0);
	mlx_destroy_image(mlx->mlx, mlx->image);
	return (0);
}
