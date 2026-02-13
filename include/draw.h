/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarapkh <akarapkh@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 18:29:51 by mickmart          #+#    #+#             */
/*   Updated: 2026/02/13 01:19:49 by mickmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# define WIN_W 1920
# define WIN_H 1080
# define FOV 1.2566f // 72 degrees pi / 2.5

# include "cube.h"
# include <stdint.h>
# include <string.h>

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
	float		current_angle;
	float		step;
	float		ray_x;
	float		ray_y;
	float		dx;
	float		dy;
	float		distance;
	float		wall_x;
	int			wall_direction;
}				t_ray_data;

typedef struct s_column_data
{
	t_texture	*current_texture;
	int			*tex_data;
	uint32_t	*fb_pixel;
	float		tex_step;
	float		tex_pos;
	int			wall_height;
	int			wall_start;
	int			wall_end;
	int			y;
	int			tex_x;
}				t_column_data;

typedef struct s_line_data
{
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			err;
	int			e2;
}				t_line_data;

typedef struct s_line_params
{
	uint32_t	color;
	int			x0;
	int			y0;
	int			x1;
	int			y1;
}				t_line_params;

typedef struct s_column_params
{
	float		distance;
	float		wall_x;
	int			x;
	int			wall_direction;
}				t_column_params;

typedef struct s_cast_ray_data
{
	float		delta_x;
	float		delta_y;
	float		side_x;
	float		side_y;
	int			map_x;
	int			map_y;
	int			step_x;
	int			step_y;
	int			hit;
}				t_cast_ray_data;

void			init_trig_tables(t_game *game);
float			fast_cos(t_game *game, float angle);
float			fast_sin(t_game *game, float angle);
float			ft_abs(float x);
void			put_pixel(t_texture *fb, int x, int y, uint32_t color);
void			draw_line(t_texture *fb, t_line_params *params);
void			draw_rect(t_texture *fb, int x, int y, int w, int h,
					uint32_t color);

int				get_texture_pixel(t_texture *texture, int x, int y);
int				load_all_textures(t_game *game);

void	setup_dda(t_cast_ray_data *dda, t_ray_data *ray);
int	perform_dda(t_game *g, t_cast_ray_data *dda, t_ray_data *ray);
void			cast_ray(t_game *g, t_ray_data *ray, float angle,
					float plane_angle);
int				determine_wall_direction(float ray_x, float ray_y, float dx,
					float dy);

void			draw_3d_column(t_game *g, t_column_params *params);
void			draw_ceiling(t_game *g, t_column_data *data, int x);
void			draw_floor(t_game *g, t_column_data *data, int x);

int				is_in_fov(t_game *g, float mx, float my, float radius);
void			draw_minimap_pixel(t_game *g, int *pos, int *center);
void			get_minimap_center(int *result);
void			draw_circular_grid(t_game *g, int *center);
void			draw_player_on_minimap(t_game *g, int *center);
void			draw_player_dot(t_game *g);
void			draw_grid(t_game *g);
void			draw_player_ray(t_game *g);
void			draw_fov_cone(t_game *g);

#endif
