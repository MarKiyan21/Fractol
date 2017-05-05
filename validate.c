/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 15:17:53 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/02/28 16:04:20 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	validate_num_argc(int ac)
{
	if (ac < 2 || ac > 3)
	{
		ft_putstr("\033[31mUsage: ./fractol <fractol_name>\033[0m\n");
		ft_putstr("\033[32mYou also can use two arguments fractals\033[0m\n");
		exit(0);
	}
}
