/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickmart <mickmart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:43:33 by mickmart          #+#    #+#             */
/*   Updated: 2025/12/09 23:13:41 by mickmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/draw.h"

void	render_minimap(t_game *g)
{
	draw_grid(g);
	draw_player_dot(g);
	draw_player_ray(g);
	draw_fov_cone(g);
}
