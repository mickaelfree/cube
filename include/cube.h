/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickmart <mickmart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:21:16 by mickmart          #+#    #+#             */
/*   Updated: 2025/11/04 18:06:55 by mickmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include "../libs/mlx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <stdbool.h>


typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*img;

}			t_game;

#endif
