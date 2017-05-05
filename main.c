/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 15:16:53 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/02/28 16:03:31 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int ac, char **av)
{
	int		choice;
	t_env	*env;
	pid_t	pid;

	if (ac == 10)
		return (0);
	pid = fork();
	if (pid <= 0)
	{
		validate_num_argc(ac);
		choice = choose(av[1]);
		env = init(choice);
		run(env);
	}
	else if (ac == 3)
	{
		choice = choose(av[2]);
		env = init(choice);
		run(env);
	}
	return (0);
}
