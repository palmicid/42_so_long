/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cx_file_maps_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 03:20:48 by pruangde          #+#    #+#             */
/*   Updated: 2022/11/03 03:20:51 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	cx_forbiddenthing(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if ((map[i][j] == '0') || (map[i][j] == '1') || (map[i][j] == 'C')
				|| (map[i][j] == 'E') || (map[i][j] == 'P'))
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

int	cx_square(char **map)
{
	int		i;
	size_t	count;

	i = 0;
	count = strlen(map[i]);
	i++;
	while (map[i])
	{
		if (count != strlen(map[i]))
			return (0);
		i++;
	}
	return (1);
}

int	cx_outerwall(char **map)
{
	int	x;
	int	y;

	y = strlen(map[0]);
	x = count_element_p2p(map);
	if (cx_wall_upper(map, y) == 0)
		return (0);
	if (cx_wall_left(map, x) == 0)
		return (0);
	if (cx_wall_right(map, x, y) == 0)
		return (0);
	if (cx_wall_lower(map, x, y) == 0)
		return (0);
	return (1);
}

int	cx_maplimit(char **map)
{
	int	ret;

	ret = 1;
	if (map_env_counter(map, 'C') < 1)
	{
		err_with_msg("Less collectable");
		ret = 0;
	}
	if (map_env_counter(map, 'P') != 1)
	{
		err_with_msg("Must have one player");
		ret = 0;
	}
	if (map_env_counter(map, 'E') != 1)
	{
		err_with_msg("Must have one exit");
		ret = 0;
	}
	return (ret);
}

int	cx_playable(char **map, int *coin)
{
	int		ret;
	int		x;
	int		y;
	char	**mapdup;

	x = 0;
	y = 0;
	find_pos(map, 'P', &x, &y);
	mapdup = ft_splitdup(map);
	ret = recur_fill(mapdup, x, y, coin);
	ft_free_p2p_char(mapdup);
	return (ret);
}
