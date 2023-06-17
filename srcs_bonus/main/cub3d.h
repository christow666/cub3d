/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 22:58:54 by christo           #+#    #+#             */
/*   Updated: 2023/06/16 22:13:17 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../../libs/MLX/include/MLX42/MLX42.h"
# include <errno.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <math.h>
# include <limits.h>
# include <float.h>

# include "../initialization/initialization.h"
# include "./struct.h"
# include "../object/object.h"
# include "../ray/ray.h"
# include "../parsing/map_processor.h"
# include "../features/features.h"

# define RED   "\x1B[31m"
# define GRN   "\x1B[32m"
# define YEL   "\x1B[33m"
# define BLU   "\x1B[34m"
# define MAG   "\x1B[35m"
# define CYN   "\x1B[36m"
# define WHT   "\x1B[37m"
# define RESET "\x1B[0m"

// typedef struct cub3d
// {
//     mlx_t			*mlx;
//     xpm_t           *xpm;
//     t_map           map;
// }   t_cub3d;

void	free_all(t_cub3d *cub3d);
// int8_t	initialization(t_cub3d *cub3d);

# define true 1
# define false 0

#endif