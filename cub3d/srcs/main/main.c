/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christo <christo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 22:57:27 by christo           #+#    #+#             */
/*   Updated: 2023/04/23 18:41:09 by christo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "../map/map.h"
#include "struct.h"

void	check_col(t_map *map, t_player *player)
{
	int	i;
	
	i = 0;
	while (i <= map->wall_count)
	{
		if (player->pos_x + player->d_x > map->wall_px[i] - 10
				&& player->pos_x + player->d_x < map->wall_px[i] + 110
				&& player->pos_y < map->wall_py[i] + 110
				&& player->pos_y > map->wall_py[i] - 10)
			player->col_x = 1;
		if (player->pos_y + player->d_y < map->wall_py[i] + 110
				&& player->pos_y + player->d_y > map->wall_py[i] - 10
				&& player->pos_x > map->wall_px[i] - 10
				&& player->pos_x < map->wall_px[i] + 110)
			player->col_y = 1;
		i++;
	}
}

void	calcul_new_pos(t_player *player, int d)
{
	player->d_y = d * player->speed * cos(player->angle * M_PI / 180);
	player->d_x = d * player->speed * sin(player->angle * M_PI / 180);
}

void	set_new_pos(t_player *player, t_mlx_struc *mlx)
{
	if (player->col_x == 0)
	{
		player->pos_x += player->d_x;
		mlx->img_player->instances[0].x = player->pos_x - 10;
	}
	else
		player->col_x = 0;
	if (player->col_y == 0)
	{
		player->pos_y += player->d_y;
		mlx->img_player->instances[0].y = player->pos_y - 10;
	}
	else
		player->col_y = 0;
}

void	set_direction_indicator(t_player *player, t_mlx_struc *mlx)
{
	int i;
	int	d_x;
	int	d_y;

	i = 0;
	if (mlx->img_dir_ind)
		mlx_delete_image(mlx->mlx, mlx->img_dir_ind);
	mlx->img_dir_ind = mlx_new_image(mlx->mlx, 100, 100);
	while(i < 50)
	{
		d_y = i * cos(player->angle * M_PI / 180);
		d_x = i * sin(player->angle * M_PI / 180);
		mlx_put_pixel(mlx->img_dir_ind, 50 + d_x, 50 + d_y, 0xFFFFFF);
		i++;
	}
	mlx_image_to_window(mlx->mlx, mlx->img_dir_ind,
		player->pos_x - 50, player->pos_y - 50);
}

void	calcul_ray_to_object_dis(t_player *player, t_map *map, t_ray *ray)
{
	int j;

	j = 0;
	// calculate the x and y components of the ray direction vector
	ray->dir_x = sin(player->angle * M_PI / 180);
	ray->dir_y = cos(player->angle * M_PI / 180);

	// loop over each wall in the map
	while (j < map->wall_count)
	{
		// calculate the intersection point between the ray and the current wall
		ray->inter_x = (map->wall_px[j] * 100 - player->pos_x) / ray->dir_x;
		ray->inter_y = (map->wall_px[j] * 100 - player->pos_y) / ray->dir_y;
		
		// calculate the distance between the player and the intersection point
		ray->dist = sqrt((ray->inter_x * ray->inter_x)
			+ (ray->inter_y * ray->inter_y));
		
		// if the intersection point is on the correct side of
		//the player and closer than the previous closest point,
		//update the minimum distance
		if ((ray->inter_x > 0) && (ray->inter_y > 0)
			&& (ray->dist < ray->min_dist))
				ray->min_dist = ray->dist;
		j++;
	}
	printf("dist minm :%d\n", ray->min_dist);
	// store the minimum distance found in the variable
	// rayDist = minDist;
}


void ft_loop(void *param)
{
	t_cub3d *cub3d = param;

	if (mlx_is_key_down(cub3d->mlx->mlx, MLX_KEY_UP))
	{
		calcul_new_pos(cub3d->player, 1);
		check_col(cub3d->map, cub3d->player);
		set_new_pos(cub3d->player, cub3d->mlx);
	}
	if (mlx_is_key_down(cub3d->mlx->mlx, MLX_KEY_DOWN))
	{
		calcul_new_pos(cub3d->player, -1);
		check_col(cub3d->map, cub3d->player);
		set_new_pos(cub3d->player, cub3d->mlx);
	}
	if (mlx_is_key_down(cub3d->mlx->mlx, MLX_KEY_RIGHT))
	{
		cub3d->player->angle -= 5;
	}
	if (mlx_is_key_down(cub3d->mlx->mlx, MLX_KEY_LEFT))
	{
		cub3d->player->angle += 5;
	}
	if (cub3d->tic == 10)
	{
		calcul_ray_to_object_dis(cub3d->player,cub3d->map, cub3d->ray);
		cub3d->tic = 0;
	}
	set_direction_indicator(cub3d->player, cub3d->mlx);
	cub3d->tic++;
}

void key_hook(mlx_key_data_t keydata, void *param)
{
	t_cub3d *cub3d = param;

	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_terminate(cub3d->mlx->mlx);
		free(cub3d->map->wall_px);
		free(cub3d->map->wall_py);
		free(cub3d->map->map);
		exit (0);
	}
	// set_direction_indicator(cub3d->player, cub3d->mlx);
}

void	init_ray(t_ray *ray)
{
	ray->min_dist = INT_MAX;	
}

int main(void)
{
    t_cub3d 	cub3d;
	t_mlx_struc mlx;
	t_map		map;
	t_player	player;
	t_ray		ray;
    
	cub3d.mlx = &mlx;
	cub3d.map = &map;
	cub3d.player = &player;
	cub3d.ray = &ray;
	cub3d.tic = 0;
    ft_map_init(&cub3d);
	cub3d.mlx->mlx = mlx_init(cub3d.map->lenght * 100, cub3d.map->height * 100, "cub3d", true);
	if (!cub3d.mlx)
	    perror("Error opening mlx");
	ft_create_map(cub3d.map, &cub3d);
	init_ray(cub3d.ray);
	mlx_key_hook(cub3d.mlx->mlx, key_hook, &cub3d);
	mlx_loop_hook(cub3d.mlx->mlx, ft_loop, &cub3d);
	mlx_loop(cub3d.mlx->mlx);
	return (0);
}