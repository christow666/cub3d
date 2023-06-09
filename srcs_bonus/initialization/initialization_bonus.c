/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 15:06:19 by ddemers           #+#    #+#             */
/*   Updated: 2023/06/22 13:40:52 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initialization_bonus.h"

int8_t	print_error(const char *message)
{
	write(STDERR_FILENO, "Error\n", 6);
	write(STDERR_FILENO, message, ft_strlen(message));
	return (FAILURE);
}

static void	init_cub3d_struct(t_cub3d *cub3d)
{
	cub3d->tic = 0;
	cub3d->vision = 4;
	cub3d->ray = NULL;
	cub3d->map = NULL;
	cub3d->player = NULL;
	cub3d->mlx_s = NULL;
	cub3d->loop_status = 0;
	cub3d->fps_counter = false;
	cub3d->tig = 1;
}

static int8_t	alloc_struct(t_cub3d *cub3d)
{
	cub3d->map = ft_calloc(1, sizeof(t_map));
	if (!cub3d->map)
		return (FAILURE);
	cub3d->player = ft_calloc(1, sizeof(t_player));
	if (!cub3d->player)
		return (FAILURE);
	cub3d->ray = ft_calloc(1, sizeof(t_ray));
	if (!cub3d->ray)
		return (FAILURE);
	cub3d->mlx_s = ft_calloc(1, sizeof(t_mlx_struc));
	if (!cub3d->mlx_s)
		return (FAILURE);
	cub3d->hud = ft_calloc(1, sizeof(t_hud));
	if (!cub3d->hud)
		return (FAILURE);
	cub3d->racer = ft_calloc(1, sizeof(t_racer));
	if (!cub3d->racer)
		return (FAILURE);
	cub3d->timer = ft_calloc(1, sizeof(t_timer));
	if (!cub3d->timer)
		return (FAILURE);
	cub3d->countdown = ft_calloc(1, sizeof(t_lakitu));
	if (!cub3d->countdown)
		return (FAILURE);
	return (SUCCESS);
}

int8_t	init_mlx(t_cub3d *cub3d)
{
	cub3d->mlx_s->mlx = mlx_init(1400, 900, "cub3d", true);
	if (!cub3d->mlx_s->mlx)
		return (print_error("MLX INIT FAILURE\n"));
	mlx_set_cursor_mode(cub3d->mlx_s->mlx, MLX_MOUSE_HIDDEN);
	init_hooks(cub3d);
	return (SUCCESS);
}

int8_t	initialization(t_cub3d *cub3d, char *map_path)
{
	init_cub3d_struct(cub3d);
	if (alloc_struct(cub3d))
		return (print_error("Alloc failure\n"));
	map_initialization(cub3d->map, map_path);
	if (cub3d->map->map_errno)
		return (print_map_errno(cub3d->map->map_errno),
			FAILURE);
	if (init_mlx(cub3d))
		return (FAILURE);
	if (init_background(cub3d))
		return (mlx_terminate(cub3d->mlx_s->mlx), FAILURE);
	if (init_walls(cub3d))
		return (mlx_terminate(cub3d->mlx_s->mlx), FAILURE);
	if (init_hud_player(cub3d))
		return (mlx_terminate(cub3d->mlx_s->mlx), FAILURE);
	if (init_end_screen(cub3d))
		return (mlx_terminate(cub3d->mlx_s->mlx), FAILURE);
	if (init_timer(cub3d))
		return (mlx_terminate(cub3d->mlx_s->mlx), FAILURE);
	if (init_countdown(cub3d))
		return (mlx_terminate(cub3d->mlx_s->mlx), FAILURE);
	if (set_music_path(cub3d))
		return (mlx_terminate(cub3d->mlx_s->mlx), FAILURE);
	return (SUCCESS);
}
