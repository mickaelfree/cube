/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_dda.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarapkh <akarapkh@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 12:18:44 by akarapkh          #+#    #+#             */
/*   Updated: 2026/02/19 15:45:33 by akarapkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static void	update_wall_direction(t_ray_data *ray, t_cast_ray_data *dda,
				int is_vertical);

int	perform_dda(t_game *g, t_cast_ray_data *dda, t_ray_data *ray)
{
	while (1)
	{
		if (dda->side_x < dda->side_y)
		{
			dda->side_x += dda->delta_x;
			dda->map_x += dda->step_x;
			update_wall_direction(ray, dda, 1);
		}
		else
		{
			dda->side_y += dda->delta_y;
			dda->map_y += dda->step_y;
			update_wall_direction(ray, dda, 0);
		}
		if (dda->map_x < 0 || dda->map_x >= g->map.width || dda->map_y < 0
			|| dda->map_y >= g->map.height)
			return (0);
		if (g->map.grid[dda->map_y][dda->map_x] == 1)
			return (1);
	}
}

static void	update_wall_direction(t_ray_data *ray, t_cast_ray_data *dda,
		int is_vertical)
{
	if (is_vertical)
	{
		if (dda->step_x < 0)
			ray->wall_direction = EAST;
		else
			ray->wall_direction = WEST;
	}
	else
	{
		if (dda->step_y < 0)
			ray->wall_direction = SOUTH;
		else
			ray->wall_direction = NORTH;
	}
}
