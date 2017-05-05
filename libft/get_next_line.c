/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 17:31:40 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/02/13 16:37:18 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_cp_without_n(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	str[i] = '\0';
	return (str);
}

static char	*ft_free_s(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			str = str + (i + 1);
			return (str);
		}
		i++;
	}
	free(str);
	return (NULL);
}

static int	ft_find_n(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int			get_next_line(int const fd, char **line)
{
	static char	*str;
	int			ret;
	char		buff[BUFF_SIZE + 1];

	if (BUFF_SIZE < 1 || !line || fd < 0)
		return (-1);
	ret = BUFF_SIZE;
	if (str)
		*line = ft_cp_without_n(ft_strdup(str));
	while (!(ft_find_n(str)) && ret == BUFF_SIZE)
	{
		if ((ret = read(fd, buff, BUFF_SIZE)) == -1)
			return (-1);
		buff[ret] = '\0';
		if (!str)
			str = ft_strdup(buff);
		else
			str = ft_strjoin(str, buff);
	}
	*line = ft_cp_without_n(ft_strdup(str));
	str = ft_free_s(str);
	if (*line[0] == '\0' && ret < BUFF_SIZE)
		return (0);
	return (1);
}
