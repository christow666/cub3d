/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 23:38:58 by ddemers           #+#    #+#             */
/*   Updated: 2023/06/20 13:49:25 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INITIALIZATION_H
# define INITIALIZATION_H

# include "../main/struct.h"
# include "../main/cub3d.h"

# define STEP 900
# define MATH 8448

int8_t	ft_create_map(t_map *map, t_cub3d *cub3d);
// initialization.c
int8_t	initialization(t_cub3d *cub3d);
int8_t	print_error(const char *message);

// init_background.c
int8_t	init_background(t_cub3d *cub3d);

// init_walls.c
int8_t	init_walls(t_cub3d *cub3d);

// init_hud_player.c
int8_t	init_hud_player(t_cub3d *cub3d);

//
int8_t	init_timer(t_cub3d *cub3d);

// init_timer_digit.c
int8_t	load_digit1(t_cub3d *cub3d);
int8_t	load_digit2(t_cub3d *cub3d);
int8_t	load_digit3(t_cub3d *cub3d);

// init_end_screen.c
int8_t	init_end_screen(t_cub3d *cub3d);

// init_countdown.c
int8_t	init_countdown(t_cub3d *cub3d);

#endif