/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 15:38:02 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/02/27 10:51:45 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		choose(char *fractal)
{
	if (ft_strcmp(ft_lowercase(fractal), "mandelbrot") == 0)
		return (1);
	else if (ft_strcmp(ft_lowercase(fractal), "julia") == 0)
		return (2);
	else if (ft_strcmp(ft_lowercase(fractal), "flower_power") == 0)
		return (3);
	else if (ft_strcmp(ft_lowercase(fractal), "the_batman") == 0)
		return (4);
	else
	{
		ft_putstr("\033[31mWrong argument name:\033[0m \033[32mtry -> \
'mandelbrot'\n\t\t\t    'julia'\n\t\t\t    'flower_power'\n\t\t\t    \
'the_batman'\033[0m\n");
		exit(0);
	}
}
