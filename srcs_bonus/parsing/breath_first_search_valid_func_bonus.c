/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   breath_first_search_valid_func_bonus.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:18:40 by ddemers           #+#    #+#             */
/*   Updated: 2023/06/22 12:57:45 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_processor_bonus.h"

bool	is_on_edge(uint16_t y, uint16_t x, t_bfs_info info)
{
	if (x == 0 || (x == info.max_x - 1) || y == 0 || y == info.max_y -1)
		return (true);
	return (false);
}

bool	is_visited(const char c)
{
	if (c == 'V')
		return (true);
	return (false);
}

bool	is_valid(const char c)
{
	if (c == '0' || c == '3' || c == '2' || c == 'C')
		return (true);
	return (false);
}

bool	is_forbidden(const char c)
{
	if (c == ' ' || c == '#')
		return (true);
	return (false);
}

bool	is_starting_point(char **map, t_cell *current)
{
	if (map[current->y][current->x] == 'N' || map[current->y][current->x] == 'S'
			|| map[current->y][current->x] == 'W'
				|| map[current->y][current->x] == 'E')
		return (true);
	return (false);
}
