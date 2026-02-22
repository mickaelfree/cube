/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_click.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarapkh <akarapkh@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 13:55:15 by akarapkh          #+#    #+#             */
/*   Updated: 2026/02/22 14:03:33 by akarapkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	mouse_click(int button, int x, int y, t_game *game)
{
	(void)x;
	(void)y;
	if (game->input.mouse_enabled == 0)
		return (0);
	if (button == 1)
		game->input.crosshair_color = 0xFF00FF00;
	else if (button == 3)
		game->input.crosshair_color = 0xFFFF0000;
	return (0);
}
