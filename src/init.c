/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmervin <tmervin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 11:44:47 by tmervin           #+#    #+#             */
/*   Updated: 2018/05/09 14:45:39 by tmervin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_cam	*cam_data(t_inf *data)
{
	t_cam	*cam;
	int		z;

	if (!(cam = (t_cam*)malloc(sizeof(t_cam))))
		return (NULL);
	z = data->z_max - data->z_min;
	cam->cx = 2.1 * data->x + z + data->y + 30;
	cam->cy = 0.5 * data->x + 0.9 * data->y + 0.6 * z + 21;
	cam->cz = 0.9 * data->x + 0.9 * data->y + 1.1 * z + 10;
	cam->ez = 1000;
	cam->tx = 90;
	cam->ty = -30;
	cam->tz = 90;
	cam->a = 1;
	cam->b = 1;
	cam->c = 1;
	return (cam);
}

void	calc_cosinus(t_inf *data)
{
	data->cam->cosx = cos(data->cam->tx * M_PI / 180);
	data->cam->cosy = cos(data->cam->ty * M_PI / 180);
	data->cam->cosz = cos(data->cam->tz * M_PI / 180);
	data->cam->sinx = sin(data->cam->tx * M_PI / 180);
	data->cam->siny = sin(data->cam->ty * M_PI / 180);
	data->cam->sinz = sin(data->cam->tz * M_PI / 180);
}

int		init_inf(t_inf *data, int ac, char **av)
{
	if (ac == 2)
	{
		if (!(data->color = color_data()))
			return (-1);
	}
	if (ac == 4)
	{
		if (!(data->color = color_data_user(av)))
			ft_usage();
		color_check(data->color);
	}
	data->fd = open(av[1], O_DIRECTORY);
	if (data->fd > 0)
		return (-1);
	data->fd = open(av[1], O_RDONLY);
	if (data->fd < 0)
		return (-1);
	data->file = av[1];
	data->x = -1;
	data->y = 0;
	if (!(data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "FILS DE FER")))
		return (-1);
	return (1);
}
