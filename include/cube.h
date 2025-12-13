/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarapkh <akarapkh@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:21:16 by mickmart          #+#    #+#             */
/*   Updated: 2025/12/13 00:18:17 by mickmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# define SCREEN_LEFT -1.0f
# define SCREEN_RIGHT 1.0f
# define SCREEN_RANGE (SCREEN_RIGHT - SCREEN_LEFT)
# define TILE_SIZE 1.0f
// binding
# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define Q 113
# define E 101
# define M 109
# define AR_LEFT 65361
# define AR_RIGHT 65363
# define MOVE_SPEED 0.02f
# define ROTATION_SPEED 0.02f
# define COLLISION_RADIUS 0.2f

# include "mlx.h"
# include <sys/time.h>
# include <unistd.h>

typedef struct s_timer
{
	struct timeval	timer;
}					t_timer;

typedef struct s_fps_counter
{
	int		frame_count;
	long	last_update;
	float	current_fps;
	int		should_update;  // Ajouter ce flag
}	t_fps_counter;

typedef struct s_map
{
	int				**grid;
	int				width;
	int				height;
}					t_map;

typedef struct s_player_vector
{
	float			x;
	float			y;
}					t_player_vector;

typedef struct s_player
{
	t_player_vector	position;
	float			angle;

}					t_player;
typedef struct s_input
{
	int				forward;
	int				backward;
	int				left;
	int				right;
	int				rotate_left;
	int				rotate_right;
	int				togle_minimap;
	int				quit;
}					t_input;

typedef struct s_texture
{
	void *img;  // image de mlx
	char *data; // data des pixel
	int				width;
	int				height;
	int bpp; // bits par pixel
	int				line_size;
	int endian; // ordre des octes
}					t_texture;

typedef struct s_parse
{
	char			*no_texture;
	char			*so_texture;
	char			*we_texture;
	char			*ea_texture;
	int				ceiling_color;
	int				floor_color;
	char			**raw_map;
	int				map_start;
	int				player_x;
	int				player_y;
	char			player_dir;
}					t_parse;

typedef struct s_config
{
	t_parse			parse;
	t_texture		texture[4];
	int				floor_r;
	int				floor_g;
	int				floor_b;
	int				ceiling_r;
	int				ceiling_g;
	int				ceiling_b;
}					t_config;

typedef struct s_game
{
	void			*mlx;
	void			*win;
	void			*img;
	t_input			input;
	t_texture		framebuffer;
	t_texture		wall_texture;
	t_map			map;
	t_player		player;
	t_config		config;
	t_fps_counter	fps;
	void			*draw_data;

}					t_game;

// TODO: faire une struct pour ranger tout les variable de draw
//
// TODO: ranger toute les fontion dans le bon fichier
void				init_hooks(t_game *g);
void				run_game(t_game *g);
void				process_input(t_game *g);
void				render_minimap(t_game *g);
int					game_loop(t_game *g);
void				render_3d_view(t_game *g);
void				init_hooks(t_game *g);
int					game_loop(t_game *g);
int					key_release(int keycode, t_game *game);
int					key_press(int keycode, t_game *game);
int					inbound(t_game *g, float x, float y);
long				get_time_ms(void);
void				fps_init(t_fps_counter *fps);
void				fps_update(t_fps_counter *fps);
void				fps_reset_stats(t_fps_counter *fps);
void				fps_print_stats(t_fps_counter *fps);
void				draw_fps_on_screen(t_game *g);

#endif
