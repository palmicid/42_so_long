/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 20:16:39 by pruangde          #+#    #+#             */
/*   Updated: 2022/10/27 20:19:04 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_window(char **map)
{
	t_progwin	*data;

	data = (t_progwin *)malloc(sizeof(t_progwin));
	data->mlx = mlx_init();
	data->dimen.win_w = count_width(map) * 30;
	data->dimen.win_h = count_height(map) * 30;
	data->window = mlx_new_window(data->mlx, data->dimen.win_w, data->dimen.win_h, "OctoSom Traveler");
	data = init_img(data);
	mapgen(map, data);
	printf("octo x = %d\n octo y = %d\n", data->octosom.x, data->octosom.y);
	
	mlx_key_hook(data->window, key_hook, &data);
	
	mlx_hook(data->window, 17, KEYPRESSMASK, &game_exit, &data);
	mlx_loop(data->mlx);
	
}

t_progwin	init_img(t_progwin *data)
{
	int	width;
	int	height;
	
	data.grass = mlx_xpm_file_to_image(data.mlx, "./resource/grass.xpm", &width, &height);
	data.wall = mlx_xpm_file_to_image(data.mlx, "./resource/wall.xpm", &width, &height);
	data.over = mlx_xpm_file_to_image(data.mlx, "./resource/deguchi.xpm", &width, &height);
	data.coin = mlx_xpm_file_to_image(data.mlx, "./resource/coin.xpm", &width, &height);
	data.octosom.f_1 = mlx_xpm_file_to_image(data.mlx, "./resource/octosom_front_1.xpm", &width, &height);
	data.octosom.f_2 = mlx_xpm_file_to_image(data.mlx, "./resource/octosom_front_2.xpm", &width, &height);
	data.octosom.x = 0;
	data.octosom.y = 0;
	data.octosom.coin = 0;
	return (data);
}

int	main(int ac, char **av)
{
	int		fd;
	char	**map;

	if (ac != 2)
	{
		write(2, "wrong argument input\n", 21);
		exit(EXIT_FAILURE);
	}
	fd = cx_file(av);
	map = cx_getmap(fd, av[1]);
	if (!map)
		err_closefile_out(fd, 0);
	close(fd);
	write(1, "Game Starto!!!!\n", 16);
	create_window(map);
	return (0);
}
