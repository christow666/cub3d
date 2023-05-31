/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_calcul.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 22:22:32 by cperron           #+#    #+#             */
/*   Updated: 2023/05/31 02:53:01 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ray.h"

void	calcul_ray_to_wall(t_player *player, t_map *map, t_ray *ray)
{
	int	j;
	t_ray_angle_s *ray_angle_s;
	
	ray_angle_s = calloc(1, sizeof(t_ray_angle_s));
	ray->ray_angle_s = ray_angle_s;
	j = 0;
	ray->min_dist = INT_MAX;
	if (cos(player->angle * M_PI / 180) < 0 && player->angle != 270)
		ray_hor_up(player, map, ray, j);
	else if(player->angle != 90)
		ray_hor_down(player, map, ray, j);
	if (sin(player->angle * M_PI / 180) > 0)
		ray_ver_right(player, map, ray, j);
	else
		ray_ver_left(player, map, ray, j);
}

void	calcul_ray_to_wall_fov(t_player *player, t_map *map, t_ray *ray)
{
	int	j;
	float fov_angle;

	j = 0;
	ray->angle_count = 0;
	fov_angle = -ray->fov_angle;
	ray->angle = player->angle - ray->fov_angle;
	while(fov_angle <= ray->fov_angle)
	{
		ray->ray_angle_fov_s[ray->angle_count]->min_dist_fov = INT_MAX;
		if (cos(ray->angle * M_PI / 180) < 0 && ray->angle != 270)
			ray_hor_up_fov(player, map, ray, j);
		else if(ray->angle != 90)
			ray_hor_down_fov(player, map, ray, j);
		if (sin(ray->angle * M_PI / 180) > 0)
			ray_ver_right_fov(player, map, ray, j);
		else
			ray_ver_left_fov(player, map, ray, j);
		ray->angle += ray->angle_div;
		fov_angle += ray->angle_div;
		ray->angle_count++;
	}
}

void ft_render(t_ray *ray, t_mlx_struc *mlx)
{
	int	i;
	float	wall_height;
	
	wall_height = 4000 / ray->min_dist;
	if (mlx->img_wall_3d)
		mlx_delete_image(mlx->mlx, mlx->img_wall_3d);
	mlx->img_wall_3d = mlx_new_image(mlx->mlx, 1900, 900);
	i = -wall_height;
	while (i < wall_height)
	{
		mlx_put_pixel(mlx->img_wall_3d, 950, 450 + i, 0xFFFFFF);
		i++;
	}
	mlx_image_to_window(mlx->mlx, mlx->img_wall_3d, 0, 0);
}

int	find_y(int i, int wall_h)
{
    double normalized_position;
    int y_pixel_pos;

    if (i < 0) {
        normalized_position = (double)i / -wall_h;
        y_pixel_pos = (int) round((normalized_position + 1.0) * 50);
    } else {
        normalized_position = (double)i / wall_h;
        y_pixel_pos = 50 - (int) round(normalized_position * 40);
    }

    return (y_pixel_pos - 5);
}


void ft_render_fov(t_cub3d * cub3d, t_player *player, t_ray *ray, t_mlx_struc *mlx)
{
	int	i;
	float j;
	int k;
	int	wall_height;
	int	y;
	int x;
	
	k = 0;
	j = -ray->fov_angle;
	if (mlx->img_wall_3d)
		mlx_delete_image(mlx->mlx, mlx->img_wall_3d);
	mlx->img_wall_3d = mlx_new_image(mlx->mlx, 1900, 1000);
	while (j < ray->angle_count - ray->fov_angle)
	{
		wall_height = 50000 / ray->ray_angle_fov_s[k]->min_dist_fov;
		i = -wall_height;
		if (i < -450)
			i = -450;
		while (i < floor(wall_height) && i < 450)
		{
			y = find_y(i, wall_height);
			x = (cub3d->ray->ray_angle_fov_s[k]->pos_on_texture);
			if (x >= 100) //feature tu fix
				x = 99;
			if (y >= 100) //feature tu fix
				y = 99;
			if (y < 0) //feature tu fix
				y = 0;
			// mlx_put_pixel(mlx->img_wall_3d, k + 500, 450 + i,
			// 	pixel_color(cub3d->xpm_s, (cub3d->ray->ray_angle_fov_s[k]->pos_on_texture / 10) ,
			// 		y));

			// mlx_put_pixel(mlx->img_wall_3d, k + 500, 450 - i,
			// 	cub3d->map->north[y][x]);
			mlx_put_pixel(mlx->img_wall_3d, 1900 - k, 450 - i,
				cub3d->map->north[y][x]);
			i++;
		}
		k++;
		j++;
	}
	set_direction_indicator_2(cub3d->player, cub3d->mlx_s, cub3d->ray);
	mlx_image_to_window(mlx->mlx, mlx->img_wall_3d, 0, 0);
}

void	ft_calcul_render(t_cub3d *cub3d)
{
	if (cub3d->tic == 60)
	{
	// 	mlx_texture_t * test =  mlx_load_png("./img/4.png");
	// 	int **fuck = fill_int_array(test->height * test->width * 4, test->height, test->width, test);
	// 	for (int i = 0; i < cub3d->mlx_s->txt_wall->height; i++)
	// {
	// 	for (int j = 0; j < cub3d->mlx_s->txt_wall->width; j++)
	// 	{
	// 		printf("%u ", cub3d->map->north[i][j]);	
	// 	}
	// }
		// printf("%u ", cub3d->map->north[9][9]);	
		cub3d->tic = 0;
	}
	if (cub3d->vision == 1)
	{
		calcul_ray_to_wall(cub3d->player,cub3d->map, cub3d->ray);
		set_direction_indicator(cub3d->player, cub3d->mlx_s);
	}
	if (cub3d->vision == 3)
	{
		calcul_ray_to_wall_fov(cub3d->player,cub3d->map, cub3d->ray);
		set_direction_indicator_3(cub3d->player, cub3d->mlx_s, cub3d->ray);
	}
	if (cub3d->vision == 4)
	{
		calcul_ray_to_wall(cub3d->player,cub3d->map, cub3d->ray);
		calcul_ray_to_wall_fov(cub3d->player,cub3d->map, cub3d->ray);
		ft_render_fov(cub3d, cub3d->player, cub3d->ray, cub3d->mlx_s);
	}
	cub3d->tic++;
}