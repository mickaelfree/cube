/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_release.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarapkh <akarapkh@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 14:03:52 by akarapkh          #+#    #+#             */
/*   Updated: 2026/02/22 14:06:41 by akarapkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	mouse_release(int button, int x, int y, t_game *game)
{
	(void)x;
	(void)y;
	if (game->input.mouse_enabled == 0)
		return (0);
	if (button == 1 || button == 3)
		game->input.crosshair_color = 0;
	return (0);
}
