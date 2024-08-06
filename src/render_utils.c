/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vini <vini@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 18:15:28 by vini              #+#    #+#             */
/*   Updated: 2024/08/06 17:33:05 by vini             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

double	get_dot_vector(t_vector vector1, t_vector vector2)
{
	double dot;

	dot = (vector1.x * vector2.x) + (vector1.y * vector2.y);
	return(dot);
}

/*
	obtiene el tamaño de un vector con la formula de pitágoras
	primero lo sumamos con la funcion existente, y luego raiz cuadrada
*/
double	get_magnitud(t_vector vector)
{
	double magnitud;

	magnitud = get_dot_vector(vector, vector);
	magnitud = sqrt(magnitud);
	return (magnitud);
}
/*
dot y magnitud_product no se que hace hay muchas mates aquí

retorna magicamente el angulo entre dos vectores pero no entiendo
 bien como lo hace
*/
float	get_angle_3d(t_vector vector1, t_vector vector2)
{
	float dot;
	float magnitud_product;

	dot = get_dot_vector(vector1, vector2);
	magnitud_product = get_magnitud(vector1) * get_magnitud(vector2);
	if (magnitud_product == 0)
		return (0);
	return (dot / magnitud_product);
}
/*
	devuelve la altura de la pared
*/
float	get_wall_height(float lengh_ray, t_vector ray_direction, t_vector player_direction, int vertical_height)
{
	double	angle;
	double	corrected_distance;
	double	wall_height;

	angle = get_angle_3d(ray_direction, player_direction);
	(void) angle;
	corrected_distance = lengh_ray; //* cos(angle);
	wall_height = vertical_height / corrected_distance;
	return (wall_height * 1450);
}

void render_rectangle(t_data *data, t_intvector coords, t_intvector size, int color)
{
	t_intvector	limit;
	t_intvector	index;

	index = coords;
	limit.x = coords.x + size.x;
	limit.y = coords.y + size.y;

	while(coords.y < limit.y)
	{
		while (coords.x < limit.x)
		{
			pixel_to_img(data, coords, color);
			coords.x++;
		}
		coords.x = index.x;
		coords.y++;
	}
}

// void	render_texture(t_data *data, t_vector coords, t_vector size, int color)
// {
// 	t_vector	limit;
// 	t_vector	index;

// 	index = coords;
// 	limit.x = coords.x + size.x;
// 	limit.y = coords.y + size.y;

// 	while(coords.y < limit.y)
// 	{
// 		while (coords.x < limit.x)
// 		{
// 			pixel_to_img(data, coords, color);
// 			coords.x++;
// 		}
// 		coords.x = index.x;
// 		coords.y++;
// 	}
// }
