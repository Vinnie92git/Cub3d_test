/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vini <vini@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 16:04:33 by vini              #+#    #+#             */
/*   Updated: 2024/08/06 17:37:45 by vini             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <errno.h>
# include <math.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
// # include "libft/libft.h"
# include "../libft/Libft/include/libft.h"
# include "../libft/ft_printf/include/ft_printf.h"
# include "../libft/Gnl/include/get_next_line.h"
# include "../mlx/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>

# define WIDTH 640
# define HEIGHT 600
# define pi 3.14159264

# ifndef O_DIRECTORY
#  define O_DIRECTORY 00200000
# endif

typedef struct s_intvector
{
	int	x;
	int	y;
}	t_intvector;

typedef struct s_vector
{
	double	x;
	double	y;
}	t_vector;

typedef struct s_ray
{
	t_vector origin;
	t_vector direction;
}	t_ray;

typedef struct s_collision
{
	float	lengh_ray;
	int		horizontal_position;
	char	direction;
	int		texture;

}	t_collision;

typedef struct s_img
{
	void	*img;
	void	*ptr;
	int		width;
	int		height;
	int		bpp;
	int		stride;
	int		endian;
}	t_img;

typedef struct s_player
{
	t_vector	position;
	t_vector	direction;
	float		fov;
}	t_player;

typedef struct s_texturedata
{
	char	*north;
	char	*south;
	char	*east;
	char	*west;
	char	**floor;
	char	**ceiling;
}	t_texturedata;

typedef struct s_filedata
{
	int		lines;
	int		fd;
	char	**file_cpy;
}	t_filedata;

typedef struct s_data
{
	int				map_height;
	void			*mlx;
	void			*win;
	void			*img;
	char			**map;
	char			**map_dup;
	t_filedata		file_data;
	t_texturedata	textures;
	t_player		player;
	t_img			wall[4];
}	t_data;

int			parse(t_data *data, char **argv);
int			count_lines(char *file);
int			count_map_height(char **file, int i);
int			map_validity(t_data *data);
int			info_validity(t_texturedata textures);
int			render(t_data *data);
int			number_to_hex(char **number);
int			keys(int key, t_data *data);
int			close_window(t_data *data);
void		init_data(t_data *data);
void		init_player(t_data *data);
void		copy_colors(t_data *data, char *line, int j);
void		copy_textures(t_data *data, char *line, int j);
void		copy_info(t_data *data, char *line, int j);
void		copy_map(t_data *data, char **file, int i);
void		fill_copy(t_data *data);
void		print_info(t_data *data);
void		print_array(char **array);
void		free_info(t_data *data);
void		free_array(char **array);
void		floodfill(char **map_dup, int x, int y);
void		duplicate_map(t_data *data);
void		render_rectangle(t_data *data, t_intvector coords, t_intvector size, int color);
// void		render_texture(t_data *data, t_vector coords, t_vector size, int color);
void		pixel_to_img(t_data *data, t_intvector coords, int color);
void		render_img_in_walls(t_data *data, int column, float wall_height, t_collision collision_data);
// void		img_in_walls(t_data *data, int column, float height, t_collision ray);
char		*ft_strdup_no_nl(char *str);
t_vector	Rotate(t_vector aPoint, float aDegree);
t_collision	ray_collision(t_data *data, t_ray ray);
float		get_wall_height(float lengh_ray, t_vector ray_direction, t_vector player_direction, int vertical_height);

#endif