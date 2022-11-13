/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapgen_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:50:50 by pruangde          #+#    #+#             */
/*   Updated: 2022/11/11 16:50:54 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_progwin	mapgen(char **map, t_progwin *data)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	y = 0;
	while (map[i])
	{
		j = 0;
		x = 0;
		while (map[i][j])
		{
			to_print(map[i][j], x, y, data);
			j++;
			x += 30;
		}
		i++;
		y += 30;
	}
	return (data);
}

t_progwin	to_print(char pos, int x, int y, t_progwin *data)
{
	if (pos == '1')
		mlx_put_image_to_window(data.mlx, data.window, data.wall, x, y);
	else if (pos == '0' || pos == 'C' || pos == 'P')
		mlx_put_image_to_window(data.mlx, data.window, data.grass, x, y);
	else if (pos == 'E')
		mlx_put_image_to_window(data.mlx, data.window, data.over, x, y);
	if (pos == 'C')
		mlx_put_image_to_window(data.mlx, data.window, data.coin, x, y);
	else if (pos == 'P')
	{
		mlx_put_image_to_window(data.mlx, data.window, data.octosom.f_1, x, y);
		data.octosom.x = x;
		data.octosom.y = y;
	}
	return (data);
}
