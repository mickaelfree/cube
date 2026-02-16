/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarapkh <akarapkh@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:17:44 by mickmart          #+#    #+#             */
/*   Updated: 2026/02/16 18:58:46 by akarapkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "parsing.h"
#include "ft_dprintf.h"
#include "libft.h"
#include <string.h>

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_dprintf(2, "Usage: %s <map.cub>\n", argv[0]);
		return (1);
	}
	game.mlx = NULL;
	game.map.grid = NULL;
	ft_memset(&game.input, 0, sizeof(t_input));
	if (parse_file(argv[1], &game) == -1)
	{
		ft_dprintf(2, "Error: Failed to parse map file\n");
		return (1);
	}
	run_game(&game);
	return (0);
}
