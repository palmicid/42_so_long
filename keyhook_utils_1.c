/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook_utils_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:55:50 by pruangde          #+#    #+#             */
/*   Updated: 2022/11/12 15:56:11 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int key, t_progwin data)
{
	if (key == KEY_ESC)
		exit(errno);
	// else if ((key == KEY_W || key == KEY_ARR_UP) && cx_wall())
	// 	// move up + octo back
	// else if (key == KEY_A || key == KEY_ARR_LEFT)
	// 	// move left + octo left
	// else if (key == KEY_S || key == KEY_ARR_DOWN)
	// 	// move down + octo front
	// else if (key == KEY_D || key == KEY_ARR_RIGHT)
	// 	// move right + octo right
	// else if (key == KEY_0)
		printf("data x %d\n", data.dimen.win_h);
	return (0);
}

int	game_exit(t_progwin data)
{
	mlx_destroy_window(data.mlx, data.window);
	exit(EXIT_SUCCESS);
	return (0);
}
