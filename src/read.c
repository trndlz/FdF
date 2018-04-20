/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmervin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 11:31:41 by tmervin           #+#    #+#             */
/*   Updated: 2018/04/20 16:24:23 by tmervin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		str_check(char *s)
{
	while (*s)
	{
		if (*s != '-' && !ft_isdigit(*s))
			return (0);
		s++;
	}
	return (1);
}

int		get_map_info(t_inf *data)
{
	char	*line;
	char	**str;
	int		x;

	data->y = 0;
	while ((get_next_line(data->fd, &line)) == 1)
	{
		x = 0;
		str = ft_strsplit(line, ' ');
		while (str[x])
		{
			if (!str_check(str[x]))
				return (-1);
			//free(str[x]);
			x++;
		}
		//free(str);
		//free(line);
		data->y++;
		data->x = x;
	}
	close(data->fd);
	data->fd = open(data->file, O_RDONLY);
	return (1);
}

int		fill_map(t_inf *data)
{
	int		x;
	int		y;
	char	**str;
	char	*line;

	if (!(data->map = (int**)malloc(sizeof(int*) * data->y)))
		return (-1);
	y = 0;
	while ((get_next_line(data->fd, &line)) == 1)
	{
		x = 0;
		if (!(data->map[y] = (int*)malloc(sizeof(int) * data->x)))
			return (-1);
		str = ft_strsplit(line, ' ');
		while (str[x])
		{
			data->map[y][x] = ft_atoi(str[x]);
			x++;
		}
		y++;
		//free(str);
		//free(line);
	}
	close(data->fd);
	return (1);
}
