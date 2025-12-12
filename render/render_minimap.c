/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarapkh <akarapkh@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:43:33 by mickmart          #+#    #+#             */
/*   Updated: 2025/12/11 23:16:34 by akarapkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	render_minimap(t_game *g)
{
	draw_grid(g);
	draw_player_dot(g);
	draw_player_ray(g);
	draw_fov_cone(g);
}
