/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fov_cone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarapkh <akarapkh@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 23:11:49 by mickmart          #+#    #+#             */
/*   Updated: 2025/12/11 23:17:50 by akarapkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "math.h"

void	draw_fov_cone(t_game *g)
{
	int		size;
	int		px;
	int		py;
	float	fov;
	float	half_fov;
	int		num_rays; float	angle_step;
	int		i;
	float	current_angle;
	float	step;
	float	ray_x;
	float	ray_y;
	float	dx;
	float	dy;
	int		end_x;
	int		end_y;

	size = WIN_W / 100;
	px = 20 + (int)(g->player.position.x * size);
	py = WIN_H - 20 - (int)((g->map.height - g->player.position.y) * size);
	fov = M_PI / 3.0f;
	half_fov = fov / 2.0f;
	num_rays = 50;
	angle_step = fov / (num_rays - 1);
	i = 0;
	while (i < num_rays)
	{
		current_angle = g->player.angle - half_fov + (i * angle_step);
		step = 0.1f;
		ray_x = g->player.position.x;
		ray_y = g->player.position.y;
		dx = cos(current_angle) * step;
		dy = sin(current_angle) * step;
		// Avancer le rayon jusqu'à collision avec un mur
		while (ray_x >= 0 && ray_x < g->map.width && ray_y >= 0
			&& ray_y < g->map.height)
		{
			if (g->map.grid[(int)ray_y][(int)ray_x] == 1)
				break ;
			ray_x += dx;
			ray_y += dy;
		}
		end_x = 20 + (int)(ray_x * size);
		end_y = WIN_H - 20 - (int)((g->map.height - ray_y) * size);
		draw_line(&g->framebuffer, px, py, end_x, end_y, 0xFFFF00);
		i++;
	}
}

