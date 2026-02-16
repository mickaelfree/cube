/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarapkh <akarapkh@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 05:06:42 by akarapkh          #+#    #+#             */
/*   Updated: 2026/02/16 13:19:15 by akarapkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include "libft.h"
#include "vectors.h"
#include <fcntl.h>

static int	store_line(char *line, t_vector *lines);

int	read_file(const char *filename, t_vector *lines)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	line = get_next_line(fd);
	if (!line)
		return (-1);
	while (line)
	{
		if (store_line(line, lines) == -1)
		{
			free(line);
			close(fd);
			return (-1);
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}

static int	store_line(char *line, t_vector *lines)
{
	char	*dup;

	dup = ft_strdup(line);
	if (!dup)
		return (-1);
	if (add_vector(lines, &dup, 1) == -1)
	{
		free(dup);
		return (-1);
	}
	return (0);
}
