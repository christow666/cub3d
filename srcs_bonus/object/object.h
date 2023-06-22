/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 22:36:09 by christo           #+#    #+#             */
/*   Updated: 2023/06/22 12:18:04 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "../main/struct.h"
# include <math.h>
# include <stdlib.h>
# include <strings.h>

//player_move
void	ft_move(t_cub3d *cub3d);
void	ft_rotate(t_cub3d *cub3d);
void	check_col(t_cub3d *cub3d, t_map *map, t_player *player);
void	calcul_new_pos(t_player *player, int x);
void	set_new_pos(t_player *player);
void	spaggetji(t_cub3d *cub3d, int x, int y);

#endif