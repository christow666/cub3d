/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   features_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 04:39:18 by ddemers           #+#    #+#             */
/*   Updated: 2023/06/22 13:21:56 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FEATURES_BONUS_H
# define FEATURES_BONUS_H

# include "../main/struct_bonus.h"
# include "../../libs/Libft/libft.h"
# include "../ray/ray_bonus.h"
# include <sys/time.h>
# include <stdlib.h>
# include <stdio.h>

/*
	 **********************************
	 ~	      Game clock/timer        ~
	 **********************************
*/
# define INTERVAL 10
# define INTERVAL_SEC 1
# define FIRST_DIGIT 1
# define MS 0
# define SECONDS 1
# define MINUTES 2
# define FAILURE -1
# define SUCCESS 0

void	game_clock(t_cub3d *cub3d);
/*
	 **********************************
	 ~	         Mushroom	          ~
	 **********************************
*/
# define MUSH_TIMER 3
# define SPEED_BOOST 40
# define MAX_SPEED 20

void	mushroom(t_cub3d *cub3d);
/*
	 **********************************
	 ~	         Animation	          ~
	 **********************************
*/
# define FORWARD 0b00000001
# define BACK 0b00000010
# define LEFT 0b00000100
# define RIGHT 0b00001000

void	animation_racer(t_cub3d *cub3d, uint8_t flag);
/*
	 **********************************
	 ~	         End_screen	          ~
	 **********************************
*/
void	end_screen(t_cub3d *cub3d);
void	set_end_screen_transition(t_cub3d *cub3d);
/*
	 **********************************
	 ~	           Hooks  	          ~
	 **********************************
*/
void	init_hooks(t_cub3d *cub3d);
void	key_hook(mlx_key_data_t keydata, void *param);
void	mouse_position(double xpos, double ypos, void *params);
/*
	 **********************************
	 ~	           FPS  	          ~
	 **********************************
*/
void	fps_counter(void);
/*
	 **********************************
	 ~	           FPS  	          ~
	 **********************************
*/
void	countdown(t_cub3d *cub3d);
void	smooth_lakitu(t_cub3d *cub3d);
/*
	 **********************************
	 ~	           MUSIC  	          ~
	 **********************************
*/
int8_t	set_music_path(t_cub3d *cub3d);
/*
	 **********************************
	 ~	           MUSIC  	          ~
	 **********************************
*/
void	lap(t_cub3d *cub3d);

void	mouse_position(double xpos, double ypos, void *params);

#endif