/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-abb <mben-abb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 04:37:28 by mben-abb          #+#    #+#             */
/*   Updated: 2024/05/11 02:29:41 by mben-abb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mov(t_data *data, int ver, int hor)
{
	if (ver == 0)
	{
		mlx_put_image_to_window(data->display, data->window, data->floor,
			((data->p_x - hor) * 60), (data->p_y * 60));
		mlx_put_image_to_window(data->display, data->window, data->player,
			((data->p_x - hor) * 60), (data->p_y * 60));
		mlx_put_image_to_window(data->display, data->window, data->floor,
			((data->p_x) * 60), (data->p_y * 60));
		mlx_put_image_to_window(data->display, data->window, data->gate,
			((data->p_x) * 60), (data->p_y * 60));
	}
	else if (ver == 1)
	{
		mlx_put_image_to_window(data->display, data->window, data->floor,
			data->p_x * 60, (data->p_y - hor) * 60);
		mlx_put_image_to_window(data->display, data->window, data->player,
			data->p_x * 60, (data->p_y - hor) * 60);
		mlx_put_image_to_window(data->display, data->window, data->floor,
			((data->p_x) * 60), (data->p_y * 60));
		mlx_put_image_to_window(data->display, data->window, data->gate,
			((data->p_x) * 60), (data->p_y * 60));
	}
}

void	def_hor_mov(t_data *data, int type)
{
	if (data->str[data->p_y][data->p_x - type] == 'E' && data->c_total == 0)
		exiting(data);
	if (data->str[data->p_y][data->p_x - type] == 'C')
	{
		if (data->str[data->p_y][data->p_x] == 'E')
			mov(data, 0, type);
		else
		{
			mlx_put_image_to_window(data->display, data->window, data->floor,
				((data->p_x - type) * 60), (data->p_y * 60));
			mlx_put_image_to_window(data->display, data->window, data->player,
				((data->p_x - type) * 60), (data->p_y * 60));
			mlx_put_image_to_window(data->display, data->window, data->floor,
				((data->p_x) * 60), (data->p_y * 60));
		}
		data->c_total--;
	}
	if (data->str[data->p_y][data->p_x - type] != '1')
	{
		if (data->str[data->p_y][data->p_x] == 'E')
			mov(data, 0, type);
		else
		{
			mlx_put_image_to_window(data->display, data->window, data->player,
				((data->p_x - type) * 60), (data->p_y * 60));
			mlx_put_image_to_window(data->display, data->window, data->floor,
				((data->p_x) * 60), (data->p_y * 60));
		}
	}
}
void	def_ver_mov(t_data *data, int type)
{
	if (data->str[data->p_y - type][data->p_x] == 'E' && data->c_total == 0)
		exiting(data);
	if (data->str[data->p_y - type][data->p_x] == 'C')
	{
		if (data->str[data->p_y][data->p_x] == 'E')
			mov(data, 1, type);
		else
		{
			mlx_put_image_to_window(data->display, data->window, data->floor,
				(data->p_x * 60), ((data->p_y - type) * 60));
			mlx_put_image_to_window(data->display, data->window, data->player,
				(data->p_x * 60), ((data->p_y - type) * 60));
			mlx_put_image_to_window(data->display, data->window, data->floor,
				(data->p_x * 60), (data->p_y * 60));
		}
		data->c_total--;
	}
	else if (data->str[data->p_y - type][data->p_x] != '1')
	{
		if (data->str[data->p_y][data->p_x] == 'E')
			mov(data, 1, type);
		else
		{
			mlx_put_image_to_window(data->display, data->window, data->player,
				(data->p_x * 60), ((data->p_y - type) * 60));
			mlx_put_image_to_window(data->display, data->window, data->floor,
				(data->p_x * 60), (data->p_y * 60));
		}
	}
}
