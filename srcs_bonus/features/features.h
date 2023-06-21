/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   features.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 04:39:18 by ddemers           #+#    #+#             */
/*   Updated: 2023/06/21 19:02:12 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FEATURES_H
# define FEATURES_H

# include "../main/cub3d.h"
# include <sys/time.h>

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

#endif