/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_all_textures.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarapkh <akarapkh@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 18:54:27 by akarapkh          #+#    #+#             */
/*   Updated: 2026/02/12 03:12:13 by mickmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "mlx.h"
#include <stdio.h>

static int	load_xpm_texture(t_game *game, t_texture *texture, char *path);

int	load_all_textures(t_game *game)
{
	if (load_xpm_texture(game, &game->north_texture,
			game->config.parse.no_texture) != 0)
		return (-1);
	if (load_xpm_texture(game, &game->east_texture,
			game->config.parse.ea_texture) != 0)
		return (-1);
	if (load_xpm_texture(game, &game->south_texture,
			game->config.parse.so_texture) != 0)
		return (-1);
	if (load_xpm_texture(game, &game->west_texture,
			game->config.parse.we_texture) != 0)
		return (-1);
	return (0);
}

static int	load_xpm_texture(t_game *game, t_texture *texture, char *path)
{
	texture->img = mlx_xpm_file_to_image(game->mlx, (char *)path,
			&texture->width, &texture->height);
	if (!texture->img)
	{
		printf("error_xpm_texture: %s\n", path);
		return (-1);
	}
	texture->data = mlx_get_data_addr(texture->img, &texture->bpp,
			&texture->line_size, &texture->endian);
	return (0);
}
