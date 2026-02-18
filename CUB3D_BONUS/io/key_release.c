/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_release.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarapkh <akarapkh@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 22:50:45 by akarapkh          #+#    #+#             */
/*   Updated: 2025/12/11 23:08:38 by akarapkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	key_release(int keycode, t_game *game)
{
	if (keycode == ESC)
		game->input.quit = 0;
	if (keycode == W)
		game->input.forward = 0;
	if (keycode == A)
		game->input.left = 0;
	if (keycode == S)
		game->input.backward = 0;
	if (keycode == D)
		game->input.right = 0;
	if (keycode == Q)
		game->input.rotate_right = 0;
	if (keycode == E)
		game->input.rotate_left = 0;
	if (keycode == AR_LEFT)
		game->input.rotate_right = 0;
	if (keycode == AR_RIGHT)
		game->input.rotate_left = 0;
	return (0);
}
