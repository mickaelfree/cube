/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickmart <mickmart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:52:38 by mickmart          #+#    #+#             */
/*   Updated: 2025/10/06 15:52:41 by mickmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/cube.h"

int	load_xpm_texture(t_game *game, t_texture *texture, char *path)
{
	texture->img = mlx_xpm_file_to_image(game->mlx, path, 
		&texture->width, &texture->height);
	if (!texture->img)
		return (0);
	texture->data = (int *)mlx_get_data_addr(texture->img, 
		&texture->bpp, &texture->line_size, &texture->endian);
	return (1);
}

int	get_texture_pixel(t_texture *texture, int x, int y)
{
	if (x < 0 || x >= texture->width || y < 0 || y >= texture->height)
		return (0);
	return (texture->data[y * texture->width + x]);
}
void	load_all_textures(t_game *game)
{

        if (!load_xpm_texture(game, &game->framebuffer, "assets/default.xpm"))
                exit(0);
}

