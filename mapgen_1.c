/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapgen_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:50:50 by pruangde          #+#    #+#             */
/*   Updated: 2023/01/11 11:21:10 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mapgen(t_progwin *data)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	y = 0;
	while (data->map[i])
	{
		j = 0;
		x = 0;
		while (data->map[i][j])
		{
			to_print(data->map[i][j], x, y, data);
			j++;
			x += 30;
		}
		i++;
		y += 30;
	}
	if (data->end_game == 1)
		mlx_string_put(data->mlx, data->window, data->dimen.win_w / 5,
			data->dimen.win_h / 2, 0, "GAME OVER PRESS ANY KEY TO CLOSE");
}

void	to_print(char pos, int x, int y, t_progwin *data)
{
	if (pos == WALL)
		mlx_put_image_to_window(data->mlx, data->window, data->wall, x, y);
	else if (pos == FLOOR || pos == COLLECT || pos == OCTOSOM)
		mlx_put_image_to_window(data->mlx, data->window, data->grass, x, y);
	else if (pos == DOOR)
		mlx_put_image_to_window(data->mlx, data->window, data->over, x, y);
	if (pos == COLLECT)
		mlx_put_image_to_window(data->mlx, data->window, data->coin, x, y);
	else if (pos == OCTOSOM)
	{
		if (data->end_game == 1)
			mlx_put_image_to_window(data->mlx, data->window, data->octosom.f_2, x, y);
		else
			mlx_put_image_to_window(data->mlx, data->window, data->octosom.f_1, x, y);
		data->octosom.x = x / 30;
		data->octosom.y = y / 30;
	}
}

int	loop_window(t_progwin *data)
{
	mlx_clear_window(data->mlx, data->window);
	mapgen(data);
	return (0);
}
