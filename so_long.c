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
	write(1, "Game Starto!!!!\n", 16);
	close(fd);
	ft_free_p2p_char(map);
	return (0);
}
