/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vini <vini@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 13:34:07 by vini              #+#    #+#             */
/*   Updated: 2024/08/06 16:49:16 by vini             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	close_window(t_data *data)
{
	if (data->win && data->mlx)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		mlx_loop_end(data->mlx);
		free(data->mlx);
	}
	exit(0);
	return (0);
}

int	number_to_hex(char **number)
{
	int hex;
	int r;
	int g;
	int b;

	r = ft_atoi(number[0]);
	g = ft_atoi(number[1]);
	b = ft_atoi(number[2]);
	hex = r;
	hex = (hex << 8) + g;
	hex = (hex << 8) + b;
	return (hex);
}

void	duplicate_map(t_data *data)
{
	int	i;

	i = 0;
	data->map_dup = ft_calloc(data->map_height + 1, sizeof(char *));
	if (!data->map_dup)
		return ;
	while (i < data->map_height)
	{
		data->map_dup[i] = ft_strdup(data->map[i]);
		i++;
	}
}

void	floodfill(char **map_dup, int x, int y)
{
	map_dup[y][x] = 'x';
	if (y > 0 && map_dup[y - 1][x] != '1' && map_dup[y - 1][x] != 'x')
		floodfill(map_dup, x, y - 1);
	if (map_dup[y][x + 1] != '\0'
		&& map_dup[y][x + 1] != '1' && map_dup[y][x + 1] != 'x')
		floodfill(map_dup, x + 1, y);
	if (map_dup[y + 1] != NULL
		&& map_dup[y + 1][x] != '1' && map_dup[y + 1][x] != 'x')
		floodfill(map_dup, x, y + 1);
	if (x > 0 && map_dup[y][x - 1] != '1' && map_dup[y][x - 1] != 'x')
		floodfill(map_dup, x - 1, y);
}
