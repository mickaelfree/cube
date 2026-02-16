/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_map_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarapkh <akarapkh@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 03:27:10 by akarapkh          #+#    #+#             */
/*   Updated: 2026/02/16 20:10:31 by akarapkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "vectors.h"

int	store_map_line(char *line, t_vector *map_lines)
{
	char	*dup;

	dup = ft_strdup(line);
	if (!dup)
		return (-1);
	if (add_vector(map_lines, &dup, 1) == -1)
	{
		free(dup);
		return (-1);
	}
	return (0);
}
