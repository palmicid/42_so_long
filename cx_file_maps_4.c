/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cx_file_maps_4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:18:16 by pruangde          #+#    #+#             */
/*   Updated: 2022/11/03 15:18:21 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_env_counter(char **map, char c)
{
	int	i;
	int	j;
	int	sum;

	i = 0;
	sum = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				sum++;
			j++;
		}
		i++;
	}
	return (sum);
}

void	find_pos(char **map, char find, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == find)
			{
				*x = i;
				*y = j;
				return ;
			}
			j++;
		}
		i++;
	}
}
