/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:41:28 by pruangde          #+#    #+#             */
/*   Updated: 2022/10/31 15:41:41 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include <stdio.h>
# include <math.h>
# include <stdio.h>
# include <errno.h>
# include <sys/errno.h>
# include <string.h>

// cx_file_maps_1
int		cx_file(char **av);
char	**cx_getmap(int fd, char *fname);
int		countcharfile(char *fname);
int		cx_mapvalid(char **map);

// cx_file_maps_2
int		cx_forbiddenthing(char **map);
int		cx_square(char **map);
int		cx_outerwall(char **map);
int		cx_maplimit(char **map);
int		cx_playable(char **map);

// cx_file_maps_3
int		cx_wall_upper(char **map, int y);
int		cx_wall_left(char **map, int x);
int		cx_wall_right(char **map, int x, int y);
int		cx_wall_lower(char **map, int x, int y);
int		recur_fill(char **map, int x, int y);

// cx_file_maps_4
int		map_env_counter(char **map, char c);
void	find_pos(char **map, char find, int *x, int *y);

// error_handle
void	err_closefile_out(int fd, char *str);
void	err_with_msg(char *str);

#endif
