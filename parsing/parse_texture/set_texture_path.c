/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarapkh <akarapkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 05:08:54 by akarapkh          #+#    #+#             */
/*   Updated: 2025/11/27 05:50:01 by akarapkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parsing.h"
#include <stddef.h>

static char	**get_texture_ptr(t_parse *parse, size_t id);

int	set_texture_path(char *line, t_parse *parse, size_t id)
{
	char	**texture_ptr;
	char	*path;

	texture_ptr = get_texture_ptr(parse, id);
	if (!texture_ptr || *texture_ptr != NULL)
		return (-1);
	path = skip_spaces(line + 3);
	*texture_ptr = ft_strtrim(path, " \t\n");
	if (*texture_ptr == NULL)
		return (-1);
	return (0);
}

static char	**get_texture_ptr(t_parse *parse, size_t id)
{
	if (id == ID_NO)
		return (&parse->no_texture);
	if (id == ID_SO)
		return (&parse->so_texture);
	if (id == ID_WE)
		return (&parse->we_texture);
	if (id == ID_EA)
		return (&parse->ea_texture);
	return (NULL);
}
