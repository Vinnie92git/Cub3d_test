/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vini <vini@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 16:02:11 by vini              #+#    #+#             */
/*   Updated: 2024/08/06 16:13:02 by vini             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (0);
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Cube3D");
	if (data->win == NULL)
		return (0);
	return (1);
}

static void	setup_textures(t_data *data)
{
	int	i;

	i = 0;
	data->wall[0].img = mlx_xpm_file_to_image(data->mlx, data->textures.north, &(data->wall[0].width), &(data->wall[0].height));
	data->wall[1].img = mlx_xpm_file_to_image(data->mlx, data->textures.south, &(data->wall[1].width), &(data->wall[1].height));
	data->wall[2].img = mlx_xpm_file_to_image(data->mlx, data->textures.east, &(data->wall[2].width), &(data->wall[2].height));
	data->wall[3].img = mlx_xpm_file_to_image(data->mlx, data->textures.west, &(data->wall[3].width), &(data->wall[3].height));
	
	while (i < 4)
	{
		data->wall[i].ptr = mlx_get_data_addr(data->wall[i].img, &data->wall[i].bpp, &data->wall[i].stride, &data->wall[i].endian);
		data->wall[i].bpp /= 8;
		data->wall[i].width = data->wall[i].stride / data->wall[i].bpp;
		data->wall[i].height = data->wall[i].stride / data->wall[i].bpp;
		i++;
	}
}

void	check_validity(t_data *data)
{
	duplicate_map(data);
	floodfill(data->map_dup, data->player.position.x, data->player.position.y);
	if (!map_validity(data))
		printf("ERROR IN MAP VALIDATION\n");
	else if (!info_validity(data->textures))
		printf("ERROR IN TEXTURES VALIDATION\n");
	else
		printf("MAP IS COOL\n");
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (1);
	init_data(&data);
	if (!parse(&data, argv))
		return (1);
	init_player(&data);
	check_validity(&data);
	if (!init_mlx(&data))
		return (1);
	// data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	setup_textures(&data);
	mlx_loop_hook(data.mlx, &render, &data);
	mlx_hook(data.win, 2, 1L << 0, keys, &data);
	mlx_hook(data.win, 17, 1L << 17, close_window, &data);
	mlx_loop(data.mlx);
	free_array(data.file_data.file_cpy);
	free_array(data.map);
	free_array(data.map_dup);
	free_info(&data);
	close_window(&data);
	return (0);
}
