/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vini <vini@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 13:01:55 by vini              #+#    #+#             */
/*   Updated: 2024/08/06 17:40:53 by vini             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	render_camera(t_data *data)
{
	t_collision collision_data;
	t_ray tmp_ray;
	float	wall_height;

	data->player.fov = 60;
	tmp_ray.origin.x = (data->player.position.x * 32) + 16;
	tmp_ray.origin.y = (data->player.position.y * 32) + 16;
	tmp_ray.direction = Rotate(data->player.direction, (-data->player.fov/ 2));
	int i = 0;
 	while(i < WIDTH)
	{
		collision_data = ray_collision(data, tmp_ray);
		wall_height = get_wall_height(collision_data.lengh_ray, tmp_ray.direction, data->player.direction, HEIGHT);
		render_img_in_walls(data, i, wall_height, collision_data);
		tmp_ray.direction = Rotate(tmp_ray.direction, (data->player.fov / WIDTH));
		i++;
	}
}

void	render_background(t_data *data)
{
	int			color_floor;
	int			color_sky;
	t_intvector	coords;
	t_intvector	size;

	color_floor = number_to_hex(data->textures.floor);
	color_sky = number_to_hex(data->textures.ceiling);

	coords.x = 0;
	coords.y = 0;
	size.x = WIDTH;
	size.y = HEIGHT / 2;
	render_rectangle(data, coords, size, color_sky);

	coords.y = (HEIGHT / 2);
	render_rectangle(data, coords, size, color_floor);
}

// static void	render_background(t_data *data)
// {
// 	int			color_floor;
// 	int			color_sky;
// 	t_vector	coords;
// 	t_vector	size;

// 	color_floor = number_to_hex(data->textures.floor);
// 	color_sky = number_to_hex(data->textures.ceiling);

// 	coords.x = 0;
// 	coords.y = 0;
// 	size.x = WIDTH;
// 	size.y = HEIGHT / 2;
// 	render_rectangle(data, coords, size, color_sky);

// 	coords.y = (HEIGHT / 2);
// 	render_rectangle(data, coords, size, color_floor);
// }

int	render(t_data *data)
{
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	render_background(data);
	render_camera(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_destroy_image(data->mlx, data->img);
	return (0);
}
