/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickmart <mickmart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 11:59:56 by mickmart          #+#    #+#             */
/*   Updated: 2025/11/06 13:57:30 by mickmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

#include <X11/X.h>
#include <X11/keysym.h>
#define ESC 65307
#define W 119
#define A 97
#define S 115
#define D 100
#define Q 113
#define E 101
#define AR_LEFT 65361
#define AR_RIGHT 65363



static int inbound(t_game *g,float x,float y)
{
        int map_x;
        int map_y;

        map_x = (int)x;
        map_y = (int)y;
        if(map_x < 0 || map_x >= g->map.width || map_y < 0 || map_y >= g->map.height)
                return (0);
        return (g->map.grid[map_y][map_x] == 0);

}
int key_press(int keycode,t_game *game)
{
        if (keycode == ESC )
                game->input.quit = 1;
        if (keycode == A)
                game->input.left = 1;
        if (keycode == W )
                game->input.forward = 1;
        if (keycode == S)
                game->input.backward = 1;
        if (keycode == D)
                game->input.right= 1;
        if (keycode == Q)
                game->input.rotate_right= 1;
        if (keycode == E)
                game->input.rotate_left= 1;
        if (keycode == AR_LEFT)
                game->input.rotate_right= 1;
        if (keycode == AR_RIGHT)
                game->input.rotate_left= 1;
        return (0);
}
int key_release(int keycode, t_game *game)
{
        if (keycode == ESC )
                game->input.quit = 0;
        if (keycode == W )
        {
                game->input.forward = 0;
                if (inbound(game,game->player.position.x,game->player.position.y - 0.1f))
                        game->player.position.y-= 0.1f;
        }
        if (keycode == A)
        {
                game->input.left = 0;
                if (inbound(game,game->player.position.x - 0.1f,game->player.position.y))
                        game->player.position.x-= 0.1f;
        }
        if (keycode == S)
        {
                game->input.backward = 0;
                if (inbound(game,game->player.position.x ,game->player.position.y + 0.1f ))
                        game->player.position.y+= 0.1f;
        }
        if (keycode == D)
        {
                game->input.right= 0;
                if (inbound(game,game->player.position.x + 0.1f,game->player.position.y))
                        game->player.position.x+= 0.1f;
        }
        if (keycode == Q)
                game->input.rotate_right= 0;
        if (keycode == E)
                game->input.rotate_left= 0;
        if (keycode == AR_LEFT)
                game->input.rotate_right= 0;
        if (keycode == AR_RIGHT)
                game->input.rotate_left= 0;
        return (0);
}

int	close_hook(t_game *game)
{
	game->input.quit = 1;
	return (0);
}

void process_input(t_game *game)
{
        (void)game;
        // if (game->input.forward == 1)
        //         game->player.position.y--;  // Up
        // if (game->input.backward == 1)
        //         game->player.position.y++;  // Down
        // if (game->input.left == 1)
        //         game->player.position.x--;  // Left
        // if (game->input.right == 1)
        //         game->player.position.x++;  // Right
}
void init_hooks(t_game *game)
{
        mlx_hook(game->win,2,1L<<0, key_press,game);
        mlx_hook(game->win,KeyRelease,KeyReleaseMask, key_release, game);
        mlx_hook(game->win,17,0, close_hook, game);
        mlx_loop_hook(game->mlx,game_loop,game);
}
