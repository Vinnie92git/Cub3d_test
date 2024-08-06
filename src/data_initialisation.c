/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_initialisation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vini <vini@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:24:23 by vini              #+#    #+#             */
/*   Updated: 2024/08/06 15:49:28 by vini             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	init_vectors(t_data *data, int i, int j)
{
	if (data->map[i][j] == 'N')
	{
		data->player.position = (t_vector){j,i};
		data->player.direction = (t_vector){0,-1};
	}
	else if (data->map[i][j] == 'S')
	{
		data->player.position = (t_vector){j,i};
		data->player.direction = (t_vector){0,1};
	}
	else if (data->map[i][j] == 'E')
	{
		data->player.position = (t_vector){j,i};
		data->player.direction = (t_vector){1,0};
	}
	else if (data->map[i][j] == 'W')
	{
		data->player.position = (t_vector){j, i};
		data->player.direction = (t_vector){-1,0};
	}
	else
		return ;
}

void	init_player(t_data *data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	data->player.fov = 0;
	data->player.direction.x = 0;
	data->player.direction.y = 0;
	data->player.position.x = 0;
	data->player.position.y = 0;
	while(data->map[i] != NULL)
	{
		while(data->map[i][j] != '\0')
		{
			init_vectors(data, i, j);
			j++;
		}
		i++;
		j = 0;
	}
}

void	init_data(t_data *data)
{
	data->map_height = 0;
	data->file_data.lines = 0;
	data->textures.north = NULL;
	data->textures.south = NULL;
	data->textures.east = NULL;
	data->textures.west = NULL;
	data->textures.floor = NULL;
	data->textures.ceiling = NULL;
}
