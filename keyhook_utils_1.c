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

int	key_hook(int key, t_progwin *data)
{
	int	x;
	int	y;

	x = data->octosom.x;
	y = data->octosom.y;
	if (key == KEY_ESC)
		game_exit(data);
	else if ((key == KEY_W || key == KEY_ARR_UP) && cx_wall(data, x, (y - 1)))
		moveto(data, x, (y - 1));
	else if ((key == KEY_A || key == KEY_ARR_LEFT) && cx_wall(data, (x - 1), y))
		moveto(data, (x - 1), y);
	else if ((key == KEY_S || key == KEY_ARR_DOWN) && cx_wall(data, x, (y + 1)))
		moveto(data, x, (y + 1));
	else if ((key == KEY_D || key == KEY_ARR_RIGHT) && cx_wall(data, (x + 1), y))
		moveto(data, (x + 1), y);
	else if (key != KEY_W && key != KEY_A && key != KEY_S && key != KEY_D
		&& key != KEY_ARR_UP && key != KEY_ARR_DOWN && key != KEY_ARR_LEFT
		&& key != KEY_ARR_RIGHT && key == KEY_H)
		print_instruct();
	return (0);
}

int	cx_wall(t_progwin *data, int x, int y)
{
	if (data->map[y][x] == WALL)
		return (0);
	return (1);
}

void	moveto(t_progwin *data, int x, int y)
{
	data->octosom.step += 1;
	
	data->map[data->octosom.y][data->octosom.x] = FLOOR;
	if (data->map[y][x] == COLLECT)
		data->octosom.coin += 1;
	else if (data->map[y][x] == DOOR)
		game_exit(data);
	data->map[y][x] = OCTOSOM;
	data->octosom.x = x;
	data->octosom.y = y;
	ft_putnbr_fd(data->octosom.step, 1);
	ft_putchar_fd('\n', 1);
}

int	game_exit(t_progwin *data)
{	
	ft_putstr_fd("END coin collect = ", 1);
	ft_putnbr_fd(data->octosom.coin, 1);
	ft_putchar_fd('\n', 1);
	ft_free_p2p_char(data->map);
	free(data);
	//mlx_destroy_window(data->mlx, data->window);
	exit(EXIT_SUCCESS);
	return (0);
}

void	print_instruct(void)
{
	ft_putendl_fd("Key instruction", 1);
	ft_putendl_fd("Move Up		:	W  or  Up arrow", 1);
	ft_putendl_fd("Move Down	:	S  or  Down arrow", 1);
	ft_putendl_fd("Move Left	:	A  or  Left arrow", 1);
	ft_putendl_fd("Move Right	:	D  or  Right arrow", 1);
	ft_putendl_fd("Exit Game	:	ESC", 1);
}
