/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarapkh <akarapkh@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 22:51:16 by akarapkh          #+#    #+#             */
/*   Updated: 2025/12/11 23:08:35 by akarapkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	key_press(int keycode, t_game *game)
{
	if (keycode == ESC)
		game->input.quit = 1;
	if (keycode == A)
		game->input.left = 1;
	if (keycode == W)
		game->input.forward = 1;
	if (keycode == S)
		game->input.backward = 1;
	if (keycode == D)
		game->input.right = 1;
	if (keycode == Q)
		game->input.rotate_right = 1;
	if (keycode == E)
		game->input.rotate_left = 1;
	if (keycode == AR_LEFT)
		game->input.rotate_right = 1;
	if (keycode == AR_RIGHT)
		game->input.rotate_left = 1;
	if (keycode == M)
		game->input.togle_minimap = !game->input.togle_minimap;
	return (0);
}
