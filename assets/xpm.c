/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarapkh <akarapkh@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:52:38 by mickmart          #+#    #+#             */
/*   Updated: 2025/12/11 23:21:14 by akarapkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include <stdio.h>
#include "mlx.h"

int	load_xpm_texture(t_game *game, t_texture *texture, char *path)
{
	texture->img = mlx_xpm_file_to_image(game->mlx, (char *)path,
			&texture->width, &texture->height);
	if (!texture->img)
	{
		printf("error_xpm_texture: %s\n", path);
		return (0);
	}
	texture->data = mlx_get_data_addr(texture->img, &texture->bpp,
			&texture->line_size, &texture->endian);
	return (1);
}

int	get_texture_pixel(t_texture *texture, int x, int y)
{
	int	*data;
	int	index;

	if (!texture || !texture->data || !texture->img)
		return (0x8B4513); // Couleur de fallback
	if (x < 0 || x >= texture->width || y < 0 || y >= texture->height)
		return (0x8B4513);
	data = (int *)texture->data;
	index = (y * texture->line_size / 4) + x; // line_size en bytes,
	return (data[index]);
}
void	load_all_textures(t_game *game)
{
	printf("load_all_textures\n");
	load_xpm_texture(game, &game->north_texture, game->config.parse.no_texture);
	load_xpm_texture(game, &game->east_texture, game->config.parse.ea_texture);

	load_xpm_texture(game, &game->south_texture, game->config.parse.ea_texture);
	load_xpm_texture(game, &game->west_texture, game->config.parse.we_texture);
	//        exit(0);
}
