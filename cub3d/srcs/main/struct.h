/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 01:55:49 by christo           #+#    #+#             */
/*   Updated: 2023/05/31 03:53:37 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "../../lib/MLX42/include/MLX42/MLX42.h"

typedef struct map
{
    char   		**map;
    int    		lenght;
    int    		height;
	float		*wall_px;
    float		*wall_py;
	int			wall_count;
	int			**north;
}   t_map;

// typedef struct xpm_s
// {
// 	char	color[10];
// 	char	code[2];
// 	char	*wall_xpm;
// } t_xpm;

typedef struct ray_angle_s
{
	float	min_dist_fov;
	int		orientation;
	int		pos_on_texture;
}	t_ray_angle_s;

typedef struct ray_angle_fov_s
{
	float	min_dist_fov;
	int		orientation;
	int		pos_on_texture;
}	t_ray_angle_fov_s;


typedef struct ray
{
	float		min_dist;
	t_ray_angle_s	*ray_angle_s;
	t_ray_angle_s	*ray_angle_fov_s[1500];
	float		dist;
	float		dir_x;
	float		dir_y;
	float		fov_angle;
	int			angle_count;
	float		angle_div;
	float		angle;
	float		xn;
	float		yn;
}	t_ray;

typedef struct player
{
    float		pos_x;
    float		pos_y;
	float		d_x;
	float		d_y;
	float		angle;
	int			speed;
	float		rot_speed;
	bool		col_x;
	bool		col_y;
}   t_player;

typedef struct mlx_struc
{
	mlx_t			*mlx;
    xpm_t           *xpm_player;
    xpm_t			*xpm_wall;
	mlx_texture_t   *txt_sky;
	mlx_texture_t   *txt_floor;
	mlx_texture_t   *txt_img;
	mlx_texture_t   *txt_wall;
	mlx_image_t		*img_player;
	mlx_image_t		*img_sky;
	mlx_image_t		*img_floor;
	mlx_image_t		*img_img;
    mlx_image_t		*img_wall;
	mlx_image_t		*img_dir_ind;
	mlx_image_t		*img_wall_3d;
}	t_mlx_struc;

typedef struct cub3d
{
	t_mlx_struc		*mlx_s;
	t_player		*player;
    t_map           *map;
	t_ray			*ray;
	// t_xpm			*xpm_s;
	int				tic;
	int				vision;
}   t_cub3d;

typedef struct wall
{
    int		pos_x;
    int		pos_y;
}   t_wall;

#endif