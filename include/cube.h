/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickmart <mickmart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:21:16 by mickmart          #+#    #+#             */
/*   Updated: 2025/11/06 12:19:02 by mickmart         ###   ########.fr       */
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

typedef struct s_vector
{
	float		x;
	float		y;
}				t_vector;

typedef struct s_player
{
	t_vector	position;
        float		angle;

}				t_player;
typedef struct s_input
{
	int			forward;
	int			backward;
	int			left;
	int			right;
	int			rotate_left;
	int			rotate_right;
        int                     togle_minimap;
	int			quit;
}				t_input;

typedef struct s_texture
{
	void *img;  // image de mlx
	int *data; // data des pixel
	int			width;
	int			height;
	int bpp; // bits par pixel
	int			line_size;
	int endian; // ordre des octes
}				t_texture;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	void		*img;
	t_input		input;
	t_texture	framebuffer;
	t_map		map;
	t_player	player;

}				t_game;

//TODO: faire une struct pour ranger tout les variable de draw
//
//TODO: ranger toute les fontion dans le bon fichier
void			init_hooks(t_game *g);
void			run_game(t_game *g);
void			process_input(t_game *g);
int				game_loop(t_game *g);
#endif
