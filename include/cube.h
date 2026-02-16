/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarapkh <akarapkh@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:21:16 by mickmart          #+#    #+#             */
/*   Updated: 2026/02/16 20:01:44 by akarapkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

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
# define MOVE_SPEED 5.0f
# define ROTATION_SPEED 3.0f
# define COLLISION_RADIUS 0.2f

# include <sys/time.h>
# include <unistd.h>

typedef struct s_trig_table
{
	float			sin_table[3600];
	float			cos_table[3600];
	float			ray_angles[1920];
	float			plane_dist;
}					t_trig_table;

typedef struct s_timer
{
	struct timeval	timer;
}					t_timer;

typedef struct s_fps_counter
{
	int				frame_count;
	long			last_update;
	float			current_fps;
	int				should_update;
}					t_fps_counter;

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
	void			*img;
	char			*data;
	int				width;
	int				height;
	int				bpp;
	int				line_size;
	int				endian;
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
	t_texture		north_texture;
	t_texture		south_texture;
	t_texture		west_texture;
	t_texture		east_texture;
	t_map			map;
	t_player		player;
	t_config		config;
	t_fps_counter	fps;
	t_trig_table	trig;
	void			*draw_data;
	float			delta_time;
	long			last_frame_time;

}					t_game;

// TODO: faire une struct pour ranger tout les variable de draw
//
// TODO: ranger toute les fontion dans le bon fichier
void				init_hooks(t_game *g);
void				run_game(t_game *g);
void				process_input(t_game *g);
void				render_minimap(t_game *g);
int					game_loop(t_game *g);
int					render_3d_view(t_game *g);
void				init_hooks(t_game *g);
int					game_loop(t_game *g);
int					key_release(int keycode, t_game *game);
int					key_press(int keycode, t_game *game);
int					inbound(t_game *g, float x, float y);
long				get_time_ms(void);
void				fps_init(t_fps_counter *fps);
void				fps_update(t_fps_counter *fps);
void				fps_reset_stats(t_fps_counter *fps);
void				draw_fps_on_screen(t_game *g);
void				cleanup_game(t_game *game);

#endif
