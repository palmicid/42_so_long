/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cx_file_maps_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:40:56 by pruangde          #+#    #+#             */
/*   Updated: 2022/10/31 15:40:58 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	cx_file(char **av)
{
	int	fd;

	if (ft_strlaststr(av[1], ".ber") == 0)
		err_closefile_out(-1, "Wrong file format expect .ber");
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd(strerror(errno), 2);
		ft_putchar_fd('\n', 2);
		exit(errno);
	}
	return (fd);
}

char	**cx_getmap(int fd, char *fname, int *coin)
{
	int		num;
	char	*strmap;
	char	**map;

	num = countcharfile(fname);
	strmap = (char *)malloc((num + 1) * sizeof(char));
	if (!strmap)
		return (NULL);
	strmap[num] = '\0';
	read(fd, strmap, num);
	map = ft_split(strmap, '\n');
	free(strmap);
	if (cx_mapvalid(map, coin) == 0)
	{
		ft_free_p2p_char(map);
		return (NULL);
	}
	return (map);
}

int	countcharfile(char *fname)
{
	int		fd;
	int		count;
	int		sum;
	char	tmp[101];

	fd = open(fname, O_RDONLY);
	sum = 0;
	tmp[100] = 0;
	while (1)
	{
		count = read(fd, tmp, 100);
		sum += count;
		if (count == 0)
			break ;
	}
	close(fd);
	return (sum);
}

int	cx_mapvalid(char **map, int *coin)
{
	if (cx_forbiddenthing(map) == 0)
	{
		err_with_msg("Map has unknown element");
		return (0);
	}
	if (cx_square(map) == 0)
	{
		err_with_msg("Map not in square shape");
		return (0);
	}
	if (cx_outerwall(map) == 0)
	{
		err_with_msg("Wall not completely surrounded");
		return (0);
	}
	if (cx_maplimit(map) == 0)
		return (0);
	if (cx_playable(map, coin) == 0)
	{
		err_with_msg("Map no possible exit");
		return (0);
	}
	return (1);
}
