/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vini <vini@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 18:43:12 by vini              #+#    #+#             */
/*   Updated: 2024/08/06 17:28:58 by vini             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_vector Rotate(t_vector aPoint, float aDegree)
{
	float rad = aDegree * (pi / 180.0);

	float s = sin(rad);
	float c = cos(rad);

	t_vector result;
	result.x = aPoint.x * c - aPoint.y * s;
	result.y = aPoint.y * c + aPoint.x * s;
	return (result);
}

void	render_img_in_walls(t_data *data, int column, float wall_height, t_collision collision_data)
{
	int color;
	int wall_y;
	int img_y;


	wall_y = 0;
	while(wall_y < (HEIGHT) && wall_y < wall_height)
	{
		img_y = wall_y * 32 / wall_height;
			color = *((int *)data->wall[collision_data.texture].ptr + ((img_y * data->wall[collision_data.texture].width) + (collision_data.horizontal_position % 32)));
			if ((HEIGHT / 2) - ((wall_height / 2) - wall_y) >= 0 && ((HEIGHT / 2) - (wall_height / 2)) <= HEIGHT)
				pixel_to_img(data, (t_intvector){column, (HEIGHT / 2) - ((wall_height / 2) - wall_y)}, color);
		wall_y++;
	}
}

void pixel_to_img(t_data *data, t_intvector coords, int color)
{
	int pixel_position;

	pixel_position = ((coords.y * WIDTH) + coords.x) * 4;
	int pixel_bits = 32;
	int line_bytes = WIDTH;
	int endian = 0;
	char *buffer = mlx_get_data_addr(data->img, &pixel_bits, &line_bytes, &endian);

	buffer[pixel_position + 3] = (color >> 24);
	buffer[pixel_position + 2] = (color >> 16) & 0xFF;
	buffer[pixel_position + 1] = (color >> 8) & 0xFF;
	buffer[pixel_position + 0] = (color) & 0xFF;
}

// void	pixel_to_img(t_data *data, t_vector coords, int color)
// {
// 	int pixel_position;

// 	pixel_position = ((coords.y * WIDTH) + coords.x) * 4;
// 	int pixel_bits = 32;
// 	int line_bytes = WIDTH;
// 	int endian = 0;
// 	char *buffer = mlx_get_data_addr(data->img, &pixel_bits, &line_bytes, &endian);

// 	buffer[pixel_position + 3] = (color >> 24);
// 	buffer[pixel_position + 2] = (color >> 16) & 0xFF;
// 	buffer[pixel_position + 1] = (color >> 8) & 0xFF;
// 	buffer[pixel_position + 0] = (color) & 0xFF;
// }
