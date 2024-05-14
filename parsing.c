#include "so_long.h"

// void    print_map(char  **str)
// {
//     int i = 0;
//     while(str[i])
//     {
//         printf("%s",str[i++]);

//     }
// }

void	ft_exit(int ex, char *mes)
{
	printf("%s\n", mes);
	exit(ex);
}

void	map_reading(t_data *data)
{
	int	i;
	int	fd;

	data->c_len = 0;
	i = 0;
	fd = open("map.ber", O_RDONLY);
	if (fd < 0)
		ft_exit(0, "ERROR");
	// data->str[i] = (char *)malloc(1);
	while (i < data->len)
	{
		// printf("hh\n");
		// printf("b %s %p \n ",data->str[i],data->str[i] );
		data->str[i] = get_next_line(fd);
		// printf("a %s %p \n ",data->str[i],data->str[i] );
		
		i++;
		// free(data->str[i]);
	}
	data->str[i] = NULL;
	// while (1)
	// {
	// 	/* code */
	// }
	// mlx_destroy_image
	if (data->str[0] == NULL)
		ft_exit(0, "ERROR");
	i = 0;
	while (data->str[i][data->c_len] && data->str[i][data->c_len] != '\n')
		data->c_len++;
}

int	get_player_position(char **str, int *x, int *y, int len)
{
	int	i;
	int	j;
	int	c_total;

	c_total = 0;
	i = 0;
	while (i < len)
	{
		j = 0;
		while (str[i][j] && str[i][j] != '\n')
		{
			if (str[i][j] == 'C')
				c_total++;
			if (str[i][j] == 'P')
			{
				*x = j;
				*y = i;
			}
			j++;
		}
		i++;
	}
	return (c_total);
}

int	valid_path(char **str, int y, int x, int x_max, int y_max)
{
	int	total_c;

	total_c = 0;
	if (str[y][x] == '1' || str[y][x] == 'X' || x < 1 || x >= x_max || y < 1
		|| y >= y_max)
		return (0);
	if (str[y][x] == 'C')
	{
		str[y][x] = 'X';
		total_c += 1;
	}
	str[y][x] = 'X';
	total_c += valid_path(str, y + 1, x, x_max, y_max);
	total_c += valid_path(str, y - 1, x, x_max, y_max);
	total_c += valid_path(str, y, x + 1, x_max, y_max);
	total_c += valid_path(str, y, x - 1, x_max, y_max);
	return (total_c);
}
void	check_width(char **str, int len)
{
	int	c_len;
	int	i;
	int	j;
	len = 0;

	c_len = 0;
	i = 0;
	j = 0;
	while (str[i][c_len] && str[i][c_len] != '\n')
		c_len++;
	i++;
	while (i < len)
	{
		j = 0;
		while (str[i][j] && str[i][j] != '\n')
			j++;
		if (c_len != j)
			ft_exit(1, "ERROR");
		i++;
	}
}
void	check_borders(char **str, int len, int c_len)
{
	int	j;

	j = 0;
	while (str[0][j] && str[0][j] != '\n')
	{
		if (str[0][j] != '1')
			ft_exit(1, "ERROR");
		j++;
	}
	j = 0;
	while (str[len - 1][j] && str[len - 1][j] != '\n')
	{
		if (str[len - 1][j] != '1')
			ft_exit(1, "ERROR");
		j++;
	}
	j = 1;
	while (j < len - 1)
	{
		if (str[j][0] != '1')
			ft_exit(1, "ERROR");
		if (str[j][c_len - 1] != '1')
			ft_exit(1, "ERROR");
		j++;
	}
}
void	elements_counter(char **str, int len)
{
	int	i;
	int	j;
	int	p;
	int	c;
	int	e;

	i = 1;
	j = 0;
	p = c = e = 0;
	while (i < len - 1)
	{
		j = 0;
		while (str[i][j] && str[i][j] != '\n')
		{
			if (str[i][j] == 'C')
				c++;
			else if (str[i][j] == 'P')
				p++;
			else if (str[i][j] == 'E')
				e++;
			j++;
		}
		i++;
	}
	if (c <= 0 || p != 1 || e != 1)
		ft_exit(1, "ERROR");
}

void	check_map_elements(char **str, int len)
{
	int i;
	int j;

	i = 1;
	while (i < len - 1)
	{
		j = 0;
		while (str[i][j] && str[i][j] != '\n')
		{
			if (str[i][j] == '1'
				|| str[i][j] == '0' | str[i][j] == 'C' | str[i][j] == 'P' | str[i][j] == 'E')
				j++;
			else
			{
				printf("ERROR\n");
				exit(0);
			}
		}
		i++;
	}
}

void free_tableau(char **tab , int count)
{
	int i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
		/* code */
	}
	// free(tab);
	
}