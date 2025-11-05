/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickmart <mickmart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:17:44 by mickmart          #+#    #+#             */
/*   Updated: 2025/11/04 15:55:46 by mickmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "include/cube.h"

int main(int argc,char **argv)
{
        t_game game;


        //TODO: faire la struct du jeux et toute les struct qui en decoule 
        //TODO: parser la map
        //parser(&game.map)

        //TODO: init le jeux
        printf("hello");
        game.mlx = NULL;
        run_game(&game);
        (void)argc;
        (void)argv;

}
