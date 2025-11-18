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

typedef struct s_map {
  int **grid;
  int width;
  int height;
} t_map;

typedef struct s_input
{
	int		forward;
	int		backward;
	int		left;
	int		right;
	int		rotate_left;
	int		rotate_right;
	int		quit;
}			t_input;

typedef struct s_texture {
	void	*img; //image de mlx
	char	*data; // data des pixel
	int		width;
	int		height;
	int		bpp; //bits par pixel
	int		line_size;
	int		endian; //ordre des octes
}	t_texture;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*img;
	t_input	input;
        t_texture	framebuffer;
        t_map	map;
        

}			t_game;


void		init_hooks(t_game *g);
void		run_game(t_game *g);
int		game_loop(t_game *g);
#endif
