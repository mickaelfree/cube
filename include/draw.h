/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickmart <mickmart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 18:29:51 by mickmart          #+#    #+#             */
/*   Updated: 2025/12/10 02:24:10 by mickmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

#define WIN_W 3840
#define WIN_H 2160
# include "../minilibx-linux/mlx.h"
#include "cube.h"
# include <stdint.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

# define SCREEN_LEFT -1.0f
# define SCREEN_RIGHT 1.0f
# define SCREEN_RANGE (SCREEN_RIGHT - SCREEN_LEFT)
# define TILE_SIZE 1.0f


float	ft_absf(float x);
void	put_pixel(t_texture *fb, int x, int y, uint32_t color);
void	draw_line(t_texture *fb, int x0, int y0, int x1, int y1, uint32_t color);
void	draw_player_dot(t_game *g);
void	draw_grid(t_game *g);
void	draw_rect(t_texture *fb, int x, int y, int w, int h, uint32_t color);
void	draw_player_ray(t_game *g);
void	draw_fov_cone(t_game *g);
void	draw_3d_column(t_game *g, int x, float distance);
int	get_texture_pixel(t_texture *texture, int x, int y);
void	load_all_textures(t_game *game);


#endif
