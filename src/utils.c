/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vini <vini@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 17:10:50 by vini              #+#    #+#             */
/*   Updated: 2024/07/24 14:10:17 by vini             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	print_info(t_data *data)
{
	printf("\n");
	if (data->textures.north)
		printf("north texture is: %s\n", data->textures.north);
	if (data->textures.south)
		printf("south texture is: %s\n", data->textures.south);
	if (data->textures.east)
		printf("east texture is: %s\n", data->textures.east);
	if (data->textures.west)
		printf("west texture is: %s\n", data->textures.west);
	if (data->textures.floor)
	{
		printf("\nfloor rgb value is: \n");
		print_array(data->textures.floor);
	}
	if (data->textures.ceiling)
	{
		printf("ceiling rgb value is: \n");
		print_array(data->textures.ceiling);
	}
}

void	print_array(char **array)
{
	int i;

	i = 0;
	printf("\n");
	while(array[i] != NULL)
	{
		printf("%s\n", array[i]);
		i++;
	}
	printf("\n");
}

void	free_info(t_data *data)
{
	if (data->textures.north)
		free(data->textures.north);
	if (data->textures.south)
		free(data->textures.south);
	if (data->textures.east)
		free(data->textures.east);
	if (data->textures.west)
		free(data->textures.west);
	if (data->textures.floor)
		free_array(data->textures.floor);
	if (data->textures.ceiling)
		free_array(data->textures.ceiling);
}

void	free_array(char **array)
{
	size_t	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	if (array)
	{
		free(array);
		array = NULL;
	}
}

char	*ft_strdup_no_nl(char *str)
{
	int		i;
	char	*duplicate;

	i = 0;
	duplicate = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!duplicate)
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			break ;
		duplicate[i] = str[i];
		i++;
	}
	duplicate[i] = '\0';
	return (duplicate);
}

