/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 22:57:27 by christo           #+#    #+#             */
/*   Updated: 2023/06/14 17:07:55 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void key_hook(mlx_key_data_t keydata, void *param)
{
	t_cub3d *cub3d;

	cub3d = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(cub3d->mlx_s->mlx);
}

#include <time.h>

void fps_counter(t_cub3d *cub3d)
{
    static clock_t	start_time = 0;
    static uint32_t	frame_count = 0;
	clock_t			current_time;
	double			elapsed_time;

	frame_count++;
	current_time = clock();
	elapsed_time = (current_time - start_time) / CLOCKS_PER_SEC;
    if (elapsed_time >= 1.0)
    {
		printf("\rFps:%.0f", frame_count - elapsed_time);
		fflush(stdout);
		frame_count = 0;
		start_time = current_time;
    }
}

void ft_loop(void *param)
{
	t_cub3d *cub3d;

	cub3d = param;
	ft_move(cub3d);
	ft_rotate(cub3d);
	ft_calcul_render(cub3d);
	fps_counter(cub3d);
	
}

int main(int argc, char **argv)
{
    t_cub3d 	cub3d;

	if (argc != 2)
		return (write(STDERR_FILENO, "Error argc\n", 11), EXIT_FAILURE);
	if (initialization(&cub3d, argv))
		return (free_all(&cub3d), EXIT_FAILURE);
	mlx_loop_hook(cub3d.mlx_s->mlx, ft_loop, &cub3d);
	mlx_key_hook(cub3d.mlx_s->mlx, key_hook, &cub3d);
	mlx_loop(cub3d.mlx_s->mlx);
	free_all(&cub3d);
	mlx_terminate(cub3d.mlx_s->mlx);
	return (EXIT_SUCCESS);
}

// texture bug