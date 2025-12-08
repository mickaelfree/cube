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
#include <stdio.h>

int	load_xpm_texture(t_game *game, t_texture *texture, char *path)
{
        printf("helle");
	texture->img = mlx_xpm_file_to_image(game->mlx, (char *)path, 
		&texture->width, &texture->height);
	if (!texture->img)
        {
                printf("error_xpm_texture: %s\n", path);
		return (0);
        }
	texture->data = mlx_get_data_addr(texture->img, 
		&texture->bpp, &texture->line_size, &texture->endian);
	return (1);
}

int	get_texture_pixel(t_texture *texture, int x, int y)
{
	int *data;
	int index;

	if (!texture || !texture->data || !texture->img)
		return (0x8B4513); // Couleur de fallback
		
	if (x < 0 || x >= texture->width || y < 0 || y >= texture->height)
		return (0x8B4513);
	
	data = (int *)texture->data;
	index = (y * texture->line_size / 4) + x;  // line_size en bytes, diviser par 4 pour int
	return (data[index]);
}
void	load_all_textures(t_game *game)
{

        printf("load_all_textures\n");
       load_xpm_texture(game, &game->wall_texture, "assets/neon_brick_wall_64.xpm");
        //        exit(0);
}

