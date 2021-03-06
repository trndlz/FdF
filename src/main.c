/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmervin <tmervin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 11:42:49 by tmervin           #+#    #+#             */
/*   Updated: 2018/05/09 14:21:02 by tmervin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	t_inf	*data;

	if (!(ac == 2 || ac == 4))
		ft_usage();
	if (!(data = malloc(sizeof(t_inf))))
		ft_malloc_error_inf();
	data->mlx = mlx_init();
	if (init_inf(data, ac, av) != 1)
		ft_invalid_file();
	if (get_map_info(data) != 1)
		ft_invalid_file();
	if (fill_map(data) != 1)
		ft_malloc_error(data);
	if (z_limits(data) != 1)
		ft_invalid_file();
	if (!(data->cam = cam_data(data)))
		ft_malloc_error(data);
	mlx_hook(data->win, 2, 3, deal_key, data);
	create_image(data);
	free(data->cam);
	free(data->color);
	free_map(data);
	free(data);
	return (0);
}
