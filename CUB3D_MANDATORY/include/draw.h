/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarapkh <akarapkh@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 18:29:51 by mickmart          #+#    #+#             */
/*   Updated: 2026/02/18 15:08:57 by akarapkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# define FOV 1.2566f

# include "cube.h"
# include <stdint.h>

# define NORTH 0
# define SOUTH 1
# define EAST 2
# define WEST 3

# define SCREEN_LEFT -1.0f
# define SCREEN_RIGHT 1.0f
# define TILE_SIZE 1.0f

typedef struct s_ray_data
{
	float			current_angle;
	float			step;
	float			ray_x;
	float			ray_y;
	float			dx;
	float			dy;
	float			distance;
	float			wall_x;
	int				wall_direction;
}					t_ray_data;

typedef struct s_column_data
{
	t_texture		*current_texture;
	int				*tex_data;
	uint32_t		*fb_pixel;
	float			tex_step;
	float			tex_pos;
	int				wall_height;
	int				wall_start;
	int				wall_end;
	int				y;
	int				tex_x;
}					t_column_data;

typedef struct s_line_data
{
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				err;
	int				e2;
}					t_line_data;

typedef struct s_line_params
{
	uint32_t		color;
	int				x0;
	int				y0;
	int				x1;
	int				y1;
}					t_line_params;

typedef struct s_column_params
{
	float			distance;
	float			wall_x;
	int				x;
	int				wall_direction;
}					t_column_params;

typedef struct s_cast_ray_data
{
	float			delta_x;
	float			delta_y;
	float			side_x;
	float			side_y;
	int				map_x;
	int				map_y;
	int				step_x;
	int				step_y;
	int				hit;
}					t_cast_ray_data;

typedef struct s_render_data
{
	t_ray_data		ray;
	t_column_params	params;
	int				x;
	float			plane_dist;
	float			current_angle;
	float			ray_angle;
}					t_render_data;

// RENDER
void				cast_ray(t_game *g, t_ray_data *ray, float angle,
						float plane_angle);
void				render_minimap(t_game *g);
int					render_3d_view(t_game *g);

// MINIMAP
void				draw_circular_grid(t_game *g, int *center);
void				draw_player_on_minimap(t_game *g, int *center);

// DRAW
void				put_pixel(t_texture *fb, int x, int y, uint32_t color);
void				draw_line(t_texture *fb, t_line_params *params);
void				draw_3d_column(t_game *g, t_column_params *params);
void				draw_ceiling(t_game *g, t_column_data *data, int x);
void				draw_fps_on_screen(t_game *g);
void				draw_floor(t_game *g, t_column_data *data, int x);

// UTILS
void				setup_dda(t_cast_ray_data *dda, t_ray_data *ray);
int					perform_dda(t_game *g, t_cast_ray_data *dda,
						t_ray_data *ray);

#endif
