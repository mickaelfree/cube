/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarapkh <akarapkh@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 23:15:45 by mickmart          #+#    #+#             */
/*   Updated: 2026/02/17 14:59:19 by akarapkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "mlx.h"
#include "libft.h"

static void	build_fps_text(char *fps_text, int fps_value);

void	draw_fps_on_screen(t_game *g)
{
	char	fps_text[32];
	int		color;

	build_fps_text(fps_text, (int)g->fps.current_fps);
	if (g->fps.current_fps >= 60)
		color = 0x00FF00;
	else if (g->fps.current_fps >= 30)
		color = 0xFFFF00;
	else
		color = 0xFF0000;
	mlx_string_put(g->mlx, g->win, 10, 20, color, fps_text);
}

static void	build_fps_text(char *fps_text, int fps_value)
{
	char	*fps_str;
	int		i;
	int		j;

	fps_text[0] = 'F';
	fps_text[1] = 'P';
	fps_text[2] = 'S';
	fps_text[3] = ':';
	fps_text[4] = ' ';
	fps_str = ft_itoa(fps_value);
	if (!fps_str)
	{
		fps_text[5] = '0';
		fps_text[6] = '\0';
		return ;
	}
	i = 0;
	j = 5;
	while (fps_str[i])
		fps_text[j++] = fps_str[i++];
	fps_text[j] = '\0';
	free(fps_str);
}
