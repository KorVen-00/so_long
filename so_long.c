/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-abb <mben-abb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 04:37:44 by mben-abb          #+#    #+#             */
/*   Updated: 2024/05/13 03:49:33 by mben-abb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl/get_next_line.h"
#include "so_long.h"
// #include <X11/X.h>
#include <fcntl.h>
#include <mlx.h>
#include <stdio.h>
#include <strings.h>


void exiting(t_data *data)
{
	int i = 0;
	mlx_destroy_image(data->display, data->player);
	mlx_destroy_image(data->display, data->gate);
	mlx_destroy_image(data->display, data->floor);
	mlx_destroy_image(data->display, data->wall);
	mlx_destroy_image(data->display, data->collect);
	while(i < data->len)
	{
		free(data->str[i]);
		i++;
	}
	free(data->str);
	mlx_destroy_window(data->display, data->window);
	free(data->display);
	exit(0);
}
void err_exiting(t_data *data, char *str)
{
	int i = 0;
	mlx_destroy_image(data->display, data->player);
	mlx_destroy_image(data->display, data->gate);
	mlx_destroy_image(data->display, data->floor);
	mlx_destroy_image(data->display, data->wall);
	mlx_destroy_image(data->display, data->collect);
	while(i < data->len)
	{
		free(data->str[i]);
		i++;
	}
	free(data->str);
	mlx_destroy_window(data->display, data->window);
	free(data->display);
	printf("%s", str);
	exit(0);
}


// void f()
// {
// 	system("leaks a.out");
// }


int	handle_no_event(t_data data)
{
	/* This function needs to exist, but it is useless for the moment */
	return (0);
}
// void f()
// {
// 	system("leaks a.out");
// }
int	main(void)
{
	// atexit(f);
	t_data	data;
	int		fd;
	char *counter ;
	bzero(&data, sizeof(t_data));
	fd = open("map.ber", O_RDONLY);
	if (fd < 0)
		ft_exit(0, "ERROR");
	while ((counter= get_next_line(fd))){
		data.len++;
		free(counter);
	}
	close(fd);
	data.str = (char **)malloc(data.len * sizeof(char **));
	map_reading(&data);
	check_width(data.str, data.len);
	check_borders(data.str, data.len, data.c_len);
	elements_counter(data.str, data.len);
	check_map_elements(data.str, data.len);
	data.c_total = get_player_position(data.str, &data.p_x, &data.p_y, data.len);
	if (valid_path(data.str, data.p_y, data.p_x, data.c_len,
			data.len) != data.c_total)
		err_exiting(&data, "ERROR");
	int i = 0;
	while(i < data.len)
	{
		free(data.str[i]);
		i++;
	}
	rend_init(&data);
	map_rendering(&data);
	mlx_hook(data.window, 2, 1L << 0, key_handler, &data);
	mlx_loop(data.display);
}
