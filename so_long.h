/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-abb <mben-abb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 06:48:14 by mben-abb          #+#    #+#             */
/*   Updated: 2024/05/13 01:31:46 by mben-abb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "gnl/get_next_line.h"
#include "Printf/ft_printf.h"
// #include "so_long.h"
// #include <fcntl.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>

typedef struct s_data
{
	void	*display;
	void	*window;
	char	**str;
	int		c_len;
	int		len;
	int		x;
	int		y;
	int		c_total;
	void	*wall;
	void	*floor;
	void	*player;
	void	*collect;
	void	*gate;
	int		p_x;
	int		p_y;
	int		moves;
}			t_data;

int			valid_path(char **str, int y, int x, int x_max, int y_max);
void		check_borders(char **str, int len, int c_len);
void		elements_counter(char **str, int len);
void		check_width(char **str, int len);
void		check_map_elements(char **str, int len);
int			get_player_position(char **str, int *x, int *y, int len);
void		rend_init(t_data *data);
void		map_rendering(t_data *data);
int			key_handler(int key, t_data *data);
void		map_reading(t_data *data);
void		ft_exit(int ex, char *mes);
void		mov(t_data *data, int ver, int hor);
void		def_ver_mov(t_data *data, int type);
void		def_hor_mov(t_data *data, int type);
void		exiting(t_data *data);

#endif