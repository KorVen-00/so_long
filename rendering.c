/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-abb <mben-abb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 04:37:08 by mben-abb          #+#    #+#             */
/*   Updated: 2024/05/02 04:37:09 by mben-abb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	rend_init(t_data *data)
{
	int	width;
	int	height;

	data->display = mlx_init();
	data->window = mlx_new_window(data->display, data->c_len * 60, data->len
			* 60, "so_long");
	width = data->c_len * 60;
	height = data->len * 60;
	data->player = mlx_xpm_file_to_image(data->display, "flaya.xpm", &width,
			&height);
	data->floor = mlx_xpm_file_to_image(data->display, "playa.xpm", &width,
			&height);
	data->wall = mlx_xpm_file_to_image(data->display, "wall.xpm", &width,
			&height);
	data->collect = mlx_xpm_file_to_image(data->display, "collect.xpm", &width,
			&height);
	data->gate = mlx_xpm_file_to_image(data->display, "gate.xpm", &width,
			&height);
}

void	map_rendering(t_data *data)
{
	int	h;
	int	l;
	int	fd;
	int	i;
	int	j;

	h = 0;
	l = 0;
	i = 0;
	close(fd);
	fd = open("map.ber", O_RDONLY);
	while (i < data->len)
	{
		data->str[i] = get_next_line(fd);
		i++;
	}
	i = 0;
	while (i < data->len)
	{
		j = 0;
		while (data->str[i][j] && data->str[i][j] != '\n')
		{
			if (data->str[i][j] == '1')
				mlx_put_image_to_window(data->display, data->window, data->wall,
					h, l);
			else
				mlx_put_image_to_window(data->display, data->window,
					data->floor, h, l);
			if (data->str[i][j] == 'P')
				mlx_put_image_to_window(data->display, data->window,
					data->player, h, l);
			else if (data->str[i][j] == 'C')
				mlx_put_image_to_window(data->display, data->window,
					data->collect, h, l);
			else if (data->str[i][j] == 'E')
				mlx_put_image_to_window(data->display, data->window, data->gate,
					h, l);
			h += 60;
			j++;
		}
		l += 60;
		h = 0;
		i++;
	}
}
