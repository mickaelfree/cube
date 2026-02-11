/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarapkh <akarapkh@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 18:29:51 by mickmart          #+#    #+#             */
/*   Updated: 2026/01/31 20:40:31 by akarapkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# define WIN_W 1920
# define WIN_H 1080
# define FOV (M_PI / 2.5f)

# include "cube.h"
# include <stdint.h>

# define NORTH 0
# define SOUTH 1
# define EAST 2
# define WEST 3

# define SCREEN_LEFT -1.0f
# define SCREEN_RIGHT 1.0f
# define SCREEN_RANGE (SCREEN_RIGHT - SCREEN_LEFT)
# define TILE_SIZE 1.0f

typedef struct s_ray_data
{
	float	current_angle;
	float	step;
	float	ray_x;
	float	ray_y;
	float	dx;
	float	dy;
	float	distance;
	float	wall_x;
	int		wall_direction;
}	t_ray_data;

float	ft_abs(float x);
void	put_pixel(t_texture *fb, int x, int y, uint32_t color);
void	draw_line(t_texture *fb, int x0, int y0, int x1, int y1,
			uint32_t color);
void	draw_player_dot(t_game *g);
void	draw_grid(t_game *g);
void	draw_rect(t_texture *fb, int x, int y, int w, int h, uint32_t color);
void	draw_player_ray(t_game *g);
void	draw_fov_cone(t_game *g);
void	draw_3d_column(t_game *g, int x, float distance, int wall_direction, float wall_x);
int		get_texture_pixel(t_texture *texture, int x, int y);
int		load_all_textures(t_game *game);
int		is_in_fov(t_game *g, float mx, float my, float radius);
void	draw_minimap_pixel(t_game *g, int *pos, int *center);
void	get_minimap_center(int *result);
void	draw_circular_grid(t_game *g, int *center);
void	draw_player_on_minimap(t_game *g, int *center);
int		determine_wall_direction(float ray_x, float ray_y, float dx, float dy);
void	cast_ray(t_game *g, t_ray_data *ray, float angle, float plane_angle);

#endif
