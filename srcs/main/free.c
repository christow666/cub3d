/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 13:39:41 by ddemers           #+#    #+#             */
/*   Updated: 2023/06/14 17:10:26 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "struct.h"

static void	free_left_over(t_cub3d *cub3d)
{
	if (cub3d->map)
		free(cub3d->map);
	if (cub3d->player)
		free(cub3d->player);
	if (cub3d->ray)
		free(cub3d->ray);
	if (cub3d->mlx_s)
		free(cub3d->mlx_s);
}

static void	destroy_textures(t_cub3d *cub3d)
{
	if (cub3d->mlx_s->txt_wall_n)
		mlx_delete_texture(cub3d->mlx_s->txt_wall_n);
	if (cub3d->mlx_s->txt_wall_s)
		mlx_delete_texture(cub3d->mlx_s->txt_wall_s);
	if (cub3d->mlx_s->txt_wall_e)
		mlx_delete_texture(cub3d->mlx_s->txt_wall_e);
	if (cub3d->mlx_s->txt_wall_w)
		mlx_delete_texture(cub3d->mlx_s->txt_wall_w);
}

static void	free_wall_array(t_cub3d *cub3d)
{
	if (cub3d->map->north)
		free_int_array(cub3d->map->north, cub3d->mlx_s->txt_wall_n->height);
	if (cub3d->map->south)
		free_int_array(cub3d->map->south, cub3d->mlx_s->txt_wall_s->height);
	if (cub3d->map->west)
		free_int_array(cub3d->map->west, cub3d->mlx_s->txt_wall_w->height);
	if (cub3d->map->east)
		free_int_array(cub3d->map->east, cub3d->mlx_s->txt_wall_e->height);
}

static void	free_ray(t_cub3d *cub3d)
{
	uint16_t	index;

	index = 0;
	while (index <= 1400)
	{
		if (!cub3d->ray->ray_angle_fov_s[index])
			break ;
		free(cub3d->ray->ray_angle_fov_s[index]);
		index++;
	}
}

void	free_all(t_cub3d *cub3d)
{
	if (cub3d->ray)
		free_ray(cub3d);
	if (cub3d->map)
	{
		free_wall_array(cub3d);
		map_struct_destructor(cub3d->map);
	}
	if (cub3d->mlx_s)
		destroy_textures(cub3d);
	free_left_over(cub3d);
}
