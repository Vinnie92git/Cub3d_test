/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vini <vini@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:22:09 by vini              #+#    #+#             */
/*   Updated: 2024/07/24 11:24:33 by vini             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	check_rgb(char **texture)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (atoi(texture[i]) < 0 || atoi(texture[i]) > 255)
		{
			printf("NOT VALID RGB VALUES\n");
			return (0);
		}
		i++;
	}
	return (1);
}

static int	is_xpm(char *path)
{
	size_t	len;

	len = ft_strlen(path);
	if ((path[len - 3] != 'x' || path[len - 2] != 'p'
			|| path[len - 1] != 'm'
			|| path[len - 4] != '.'))
		return (0);
	return (1);
}

static int	is_dir(char *path)
{
	int	fd;

	fd = open(path, O_DIRECTORY);
	if (fd >= 0)
	{
		close (fd);
		return (1);
	}
	return (0);
}

static int	check_file(char *texturepath)
{
	int	fd;

	if (is_dir(texturepath))
	{
		printf("PATH IS DIRECTORY\n");
		return (0);
	}
	fd = open(texturepath, O_RDONLY);
	if (fd == -1)
	{
		printf("CANNOT OPEN FILE\n");
		return (0);
	}
	close(fd);
	if (!is_xpm(texturepath))
	{
		printf("FILE IS NOT XPM\n");
		return (0);
	}
	return (1);
}

int	info_validity(t_texturedata textures)
{
	if (!textures.north || !textures.south || !textures.east
		|| !textures.west || !textures.floor || !textures.ceiling)
	{
		printf("MISSING TEXTURES\n");
		return (0);
	}
	if (check_file(textures.north) == 0
		|| check_file(textures.south) == 0
		|| check_file(textures.west) == 0
		|| check_file(textures.east) == 0
		|| check_rgb(textures.floor) == 0
		|| check_rgb(textures.ceiling) == 0)
		return (0);
	return (1);
}
