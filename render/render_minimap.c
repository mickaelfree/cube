/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarapkh <akarapkh@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:43:33 by mickmart          #+#    #+#             */
/*   Updated: 2026/01/29 18:13:15 by akarapkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	render_minimap(t_game *g)
{
	int	center[3];

	get_minimap_center(center);
	draw_circular_grid(g, center);
	draw_player_on_minimap(g, center);
}
