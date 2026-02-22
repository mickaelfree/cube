/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarapkh <akarapkh@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 15:15:36 by akarapkh          #+#    #+#             */
/*   Updated: 2026/02/22 16:06:50 by akarapkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "libft.h"
#include <stdlib.h>

static int	**alloc_visited(int width, int height);
static void	free_visited(int **visited, int height);
static int	flood(t_game *g, int **visited, int x, int y);

int	is_map_closed(t_game *g)
{
	int	**visited;
	int	px;
	int	py;
	int	result;

	visited = alloc_visited(g->map.width, g->map.height);
	if (!visited)
		return (-1);
	px = (int)g->player.position.x;
	py = (int)g->player.position.y;
	result = flood(g, visited, px, py);
	free_visited(visited, g->map.height);
	return (result);
}

static int	flood(t_game *g, int **visited, int x, int y)
{
	if (x < 0 || x >= g->map.width || y < 0 || y >= g->map.height)
		return (-1);
	if (visited[y][x] || g->map.grid[y][x] == 1)
		return (0);
	visited[y][x] = 1;
	if (flood(g, visited, x + 1, y) == -1)
		return (-1);
	if (flood(g, visited, x - 1, y) == -1)
		return (-1);
	if (flood(g, visited, x, y + 1) == -1)
		return (-1);
	if (flood(g, visited, x, y - 1) == -1)
		return (-1);
	return (0);
}

static int	**alloc_visited(int width, int height)
{
	int	**visited;
	int	i;
	(void)width;
	visited = ft_calloc(height, sizeof(int *));
	if (!visited)
		return (NULL);
	i = 0;
	while (i < height)
	{
		visited[i] = ft_calloc(width, sizeof(int));
		if (!visited[i])
		{
			free_visited(visited, i);
			return (NULL);
		}
		i++;
	}
	return (visited);
}

static void	free_visited(int **visited, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
}
