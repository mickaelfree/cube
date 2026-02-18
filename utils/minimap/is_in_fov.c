/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_in_fov.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarapkh <akarapkh@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 13:43:50 by akarapkh          #+#    #+#             */
/*   Updated: 2026/02/18 13:44:13 by akarapkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include <math.h>

int	is_in_fov(t_game *g, float mx, float my, float radius)
{
	float	dx;
	float	dy;
	float	dist;

	dx = mx - g->player.position.x;
	dy = my - g->player.position.y;
	dist = sqrtf(dx * dx + dy * dy);
	if (dist > radius)
		return (0);
	return (1);
}
