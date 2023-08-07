/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapgen_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:50:50 by pruangde          #+#    #+#             */
/*   Updated: 2023/08/06 23:51:15 by pruangde         ###   ########.fr       */
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
			x += 60;
		}
		i++;
		y += 60;
	}
	if (data->end_game == 1)
		mlx_string_put(data->mlx, data->window, data->dimen.win_w / 5,
			data->dimen.win_h / 2, 0, "GAME OVER PRESS ANY KEY TO CLOSE");
}

void	sprite_dct(t_progwin *data, int x, int y)
{
	data->anitime = time(NULL);
	if (data->octosom->dct == 'U')
	{
		if (data->anitime % 2 == 0)
			mlx_put_image_to_window(data->mlx, data->window, data->octosom->b_1, x, y);
		else
			mlx_put_image_to_window(data->mlx, data->window, data->octosom->b_2, x, y);
	}
	else if (data->octosom->dct == 'L')
	{
		if (data->anitime % 2 == 0)
			mlx_put_image_to_window(data->mlx, data->window, data->octosom->l_1, x, y);
		else
			mlx_put_image_to_window(data->mlx, data->window, data->octosom->l_2, x, y);
	}
	else if (data->octosom->dct == 'D')
	{
		if (data->anitime % 2 == 0)
			mlx_put_image_to_window(data->mlx, data->window, data->octosom->f_1, x, y);
		else
			mlx_put_image_to_window(data->mlx, data->window, data->octosom->f_2, x, y);
	}
	else if (data->octosom->dct == 'R')
	{
		if (data->anitime % 2 == 0)
			mlx_put_image_to_window(data->mlx, data->window, data->octosom->r_1, x, y);
		else
			mlx_put_image_to_window(data->mlx, data->window, data->octosom->r_2, x, y);
	}
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
			mlx_put_image_to_window(data->mlx, data->window, data->octosom->ot_f, x, y);
		else
			sprite_dct(data, x, y);
		data->octosom->x = x / 60;
		data->octosom->y = y / 60;
	}
}

int	loop_window(t_progwin *data)
{
	mlx_clear_window(data->mlx, data->window);
	mapgen(data);
	return (0);
}
