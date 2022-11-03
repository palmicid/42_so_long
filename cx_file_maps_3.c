/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cx_file_maps_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 08:58:12 by pruangde          #+#    #+#             */
/*   Updated: 2022/11/03 08:58:16 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	cx_wall_upper(char **map, int y)
{
	int	j;

	j = 0;
	while (j < y)
	{
		if (map[0][j] != '1')
			return (0);
		j++;
	}
	return (1);
}

int	cx_wall_left(char **map, int x)
{
	int	i;

	i = 0;
	while (i < x)
	{
		if (map[i][0] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	cx_wall_right(char **map, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	j = y - 1;
	while (i < x)
	{
		if (map[i][j] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	cx_wall_lower(char **map, int x, int y)
{
	int	i;
	int	j;

	i = x - 1;
	j = 0;
	while (j < y)
	{
		if (map[i][j] != '1')
			return (0);
		j++;
	}
	return (1);
}

int	recur_fill(char **map, int x, int y)
{
	if (map[x][y] == '1' || map[x][y] == 'F')
		return (0);
	else if (map[x][y] == 'E')
		return (1);
	else
	{
		map[x][y] = 'F';
		return (recur_fill(map, x, y + 1) + recur_fill(map, x, y - 1)
			+ recur_fill(map, x + 1, y) + recur_fill(map, x - 1, y));
	}
}
