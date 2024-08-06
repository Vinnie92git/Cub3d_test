/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vini <vini@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 18:24:37 by vini              #+#    #+#             */
/*   Updated: 2024/08/06 17:45:32 by vini             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void look_sideways_keys(int key, t_data *data)
{
	(void)data;
	//if (key == 123)
	if (key == 97)
		data->player.direction = Rotate(data->player.direction, 5.0);
	//else if (key == 124)
	if (key == 100)
		data->player.direction = Rotate(data->player.direction, -5.0);
}

void	movements_keys(int key, t_data *data)
{
	float x = 0;
	float y = 0;
	t_vector tmp;


	if (key == 65362)
	{
		int count = 0;
		while (data->map[count] != NULL)
			count++;
		x = (data->player.direction.x * 1.3) + data->player.position.x + 0.5;
		y = (data->player.direction.y * 1.3) + data->player.position.y + 0.5;
		if (!(data->map[(int)(y)][(int)(x)] == '1'))
		{
			data->player.position.x = (data->player.direction.x * 0.1) + data->player.position.x;
			data->player.position.y = (data->player.direction.y * 0.1) + data->player.position.y;
		}
	}
	else if (key == 65361)
	{
		tmp = Rotate(data->player.direction, -90);
		x = (tmp.x * 1.3) + data->player.position.x + 0.5;
		y = (tmp.y * 1.3) + data->player.position.y + 0.5;
		if (!(data->map[(int)(y)][(int)(x)] == '1'))
		{
			data->player.position.x = (tmp.x * 0.1) + data->player.position.x;
			data->player.position.y = (tmp.y * 0.1)+ data->player.position.y;
		}
	}
	if (key == 65364)
	{
		tmp = Rotate(data->player.direction, -180);
		x = (tmp.x * 1.3) + data->player.position.x + 0.5;
		y = (tmp.y * 1.3) + data->player.position.y + 0.5;
		if (!(data->map[(int)(y)][(int)(x)] == '1'))
		{
			data->player.position.x = -(data->player.direction.x * 0.1) + data->player.position.x;
			data->player.position.y = -(data->player.direction.y * 0.1)+ data->player.position.y;
		}
	}
	else if (key == 65363)
	{
		tmp = Rotate(data->player.direction, 90);
		x = (tmp.x * 1.3) + data->player.position.x + 0.5;
		y = (tmp.y * 1.3) + data->player.position.y + 0.5;
		if (!(data->map[(int)(y)][(int)(x)] == '1'))
		{
			data->player.position.x = (tmp.x * 0.1) + data->player.position.x;
			data->player.position.y = (tmp.y * 0.1)+ data->player.position.y;
		}
	}
}

int	keys(int key, t_data *data)
{
	movements_keys(key, data);
	look_sideways_keys(key, data);
	//if (key == 53)
	if (key == 65307)
	{
		printf("Bye !\n");
		close_window(data);
	}


	return (0);
}
