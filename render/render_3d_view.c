/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_3d_view.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarapkh <akarapkh@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 02:02:39 by mickmart          #+#    #+#             */
/*   Updated: 2025/12/12 01:31:56 by akarapkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include <math.h>

void	render_3d_view(t_game *g)
{
	float	fov;
	float	half_fov;
	int		x;
	float	angle_step;
	float	current_angle;
	float	step;
	float	ray_x;
	float	ray_y;
	float	dx;
	float	dy;
	float	distance;
	int		wall_direction;

	fov = M_PI / 3.0f;
	half_fov = fov / 2.0f;
	angle_step = fov / WIN_W;
	x = 0;
	while (x < WIN_W)
	{
		current_angle = g->player.angle - half_fov + (x * angle_step);
		step = 0.01f;
		ray_x = g->player.position.x;
		ray_y = g->player.position.y;
		dx = cos(current_angle) * step;
		dy = sin(current_angle) * step;
		distance = 0;
		while (ray_x >= 0 && ray_x < g->map.width && ray_y >= 0
			&& ray_y < g->map.height)
		{
			if (g->map.grid[(int)ray_y][(int)ray_x] == 1)
			{
				if (ft_abs(ray_x - floor(ray_x)) < fabs(ray_y - floor(ray_y)))
				{
					if (dx > 0)
						wall_direction = WEST;
					else
						wall_direction = EAST;
				}
				else
				{
					if (dy > 0)
						wall_direction = NORTH;
					else
						wall_direction = SOUTH;
				}
				break ;
			}
			ray_x += dx;
			ray_y += dy;
			distance += step;
		}
		distance = distance * cos(current_angle - g->player.angle);
		draw_3d_column(g, x, distance, wall_direction);
		x++;
	}
}
