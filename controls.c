/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-abb <mben-abb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 04:37:32 by mben-abb          #+#    #+#             */
/*   Updated: 2024/05/13 03:49:39 by mben-abb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	print_map(char **str, int len)
// {
// 	int	i;

// 	i = 0;
// 	while (i < len)
// 	{
// 		printf("%s", str[i++]);
// 		printf("\n");
// 	}
// }

void	hor_mov_update(t_data *data, int type)
{
	def_hor_mov(data, type);
	if (data->str[data->p_y][data->p_x - type] == 'E')
	{
		data->str[data->p_y][data->p_x] = '0';
		data->p_x -= type;
	}
	else if (data->str[data->p_y][data->p_x - type] != '1'
		&& data->str[data->p_y][data->p_x] != 'E')
	{
		data->str[data->p_y][data->p_x] = '0';
		data->str[data->p_y][data->p_x - type] = 'P';
		data->p_x -= type;
	}
	else if (data->str[data->p_y][data->p_x - type] != '1')
	{
		data->str[data->p_y][data->p_x - type] = 'P';
		data->p_x -= type;
	}
}

void	ver_mov_update(t_data *data, int type)
{
	def_ver_mov(data, type);
	if (data->str[data->p_y - type][data->p_x] == 'E')
	{
		data->str[data->p_y][data->p_x] = '0';
		data->p_y -= type;
	}
	else if (data->str[data->p_y - type][data->p_x] != '1'
		&& data->str[data->p_y][data->p_x] != 'E')
	{
		data->str[data->p_y][data->p_x] = '0';
		data->str[data->p_y - type][data->p_x] = 'P';
		data->p_y -= type;
	}
	else if (data->str[data->p_y - type][data->p_x] != '1')
	{
		data->str[data->p_y - type][data->p_x] = 'P';
		data->p_y -= type;
	}
}

int	key_handler(int key, t_data *data)
{
	if (key == 2)
		hor_mov_update(data, -1);
	else if (key == 0)
		hor_mov_update(data, 1);
	else if (key == 1)
		ver_mov_update(data, -1);
	else if (key == 13)
		ver_mov_update(data, 1);
	else if (key == 53)
	{
		mlx_destroy_window(data->display, data->window);
		exit(0);
	}
	return (0);
}
