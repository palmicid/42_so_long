/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 20:16:39 by pruangde          #+#    #+#             */
/*   Updated: 2022/11/15 20:18:46 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_window(t_progwin *data)
{
	data->mlx = mlx_init();
	data->dimen.win_w = count_width(data->map) * 30;
	data->dimen.win_h = count_height(data->map) * 30;
	data->window = mlx_new_window(data->mlx, data->dimen.win_w,
			data->dimen.win_h, "OctoSom Traveler");
	init_img(data);
	mapgen(data);
	mlx_loop_hook(data->mlx, loop_window, data);
	mlx_hook(data->window, 2, KEYPRESSMASK, key_hook, data);
	mlx_hook(data->window, 17, KEYPRESSMASK, game_exit, &data);
	mlx_loop(data->mlx);
}

void	init_img(t_progwin *data)
{
	int	width;
	int	height;

	data->grass = mlx_xpm_file_to_image(data->mlx,
			"./resource/grass.xpm", &width, &height);
	data->wall = mlx_xpm_file_to_image(data->mlx,
			"./resource/wall.xpm", &width, &height);
	data->over = mlx_xpm_file_to_image(data->mlx,
			"./resource/deguchi.xpm", &width, &height);
	data->coin = mlx_xpm_file_to_image(data->mlx,
			"./resource/coin.xpm", &width, &height);
	data->octosom.f_1 = mlx_xpm_file_to_image(data->mlx,
			"./resource/octosom_front_1.xpm", &width, &height);
	data->octosom.f_2 = mlx_xpm_file_to_image(data->mlx,
			"./resource/octosom_front_2.xpm", &width, &height);
	data->octosom.x = 0;
	data->octosom.y = 0;
	data->octosom.coin = 0;
	data->end_game = 0;
	return ;
}

int	main(int ac, char **av)
{
	int			fd;
	t_progwin	*data;

	if (ac != 2)
	{
		write(2, "wrong argument input\n", 21);
		exit(EXIT_FAILURE);
	}
	fd = cx_file(av);
	data = (t_progwin *)malloc(sizeof(t_progwin));
	data->map = cx_getmap(fd, av[1], &(data->mapcoin));
	if (!data->map)
		err_closefile_out(fd, 0);
	close(fd);
	//data->mapcoin = count_coin(data->map);
	ft_putstr_fd("COIN = ", 1);
	ft_putnbr_fd(data->mapcoin, 1);
	ft_putchar_fd('\n', 1);
	write(1, "Game Starto!!!!\n", 16);
	create_window(data);
	return (0);
}
