/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarapkh <akarapkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:21:16 by mickmart          #+#    #+#             */
/*   Updated: 2025/11/28 04:48:07 by akarapkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include "../minilibx-linux/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

# define SCREEN_LEFT -1.0f
# define SCREEN_RIGHT 1.0f
# define SCREEN_RANGE (SCREEN_RIGHT - SCREEN_LEFT)
# define TILE_SIZE 1.0f

typedef struct s_map
{
	int			**grid;
	int			width;
	int			height;
}				t_map;

typedef struct s_input
{
	int			forward;
	int			backward;
	int			left;
	int			right;
	int			rotate_left;
	int			rotate_right;
	int			quit;
}				t_input;

typedef struct s_parse
{
	char		*no_texture;
	char		*so_texture;
	char		*we_texture;
	char		*ea_texture;
	int			ceiling_color;
	int			floor_color;
	char		**raw_map;
	int			map_start;
	int			player_x;
	int			player_y;
	char		player_dir;
}				t_parse;

typedef struct s_texture
{
	void *img;  //image de mlx
	char *data; // data des pixel
	int			width;
	int			height;
	int bpp; //bits par pixel
	int			line_size;
	int endian; //ordre des octes
}				t_texture;

typedef struct s_config
{
	t_parse		parse;
	t_texture	texture[4];
	int			floor_r;
	int			floor_g;
	int			floor_b;
	int			ceiling_r;
	int			ceiling_g;
	int			ceiling_b;
}				t_config;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	void		*img;
	t_input		input;
	t_texture	framebuffer;
	t_map		map;
	t_config	config;
}				t_game;

void			init_hooks(t_game *g);
void			run_game(t_game *g);
int				game_loop(t_game *g);
#endif
