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
# include "mlx/mlx.h"
# include "keymacair_m2.h"

# include <stdio.h>
# include <math.h>
# include <stdio.h>
# include <errno.h>
# include <sys/errno.h>
# include <string.h>
# include <time.h>


typedef	struct	s_map_dimen
{
	int	w;
	int h;
	int	win_w;
	int	win_h;
}		t_map_dimen;

typedef struct s_player
{
	void	*f_1;
	void	*f_2;
	int		step;
	int		x;
	int		y;
	int		coin;
}			t_player;

typedef struct s_progwin
{
	void		*mlx;
	void		*window;
	void		*grass;
	void		*wall;
	void		*over;
	void		*coin;
	t_map_dimen	dimen;
	t_player	octosom;
	char		**map;

}			t_progwin;

# define WALL 		'1'
# define FLOOR 		'0'
# define OCTOSOM	'P'
# define DOOR 		'E'
# define COLLECT	'C'

// so_long
void		create_window(t_progwin *data);
void		init_img(t_progwin *data);

// cx_file_maps_1
int			cx_file(char **av);
char		**cx_getmap(int fd, char *fname);
int			countcharfile(char *fname);
int			cx_mapvalid(char **map);

// cx_file_maps_2
int			cx_forbiddenthing(char **map);
int			cx_square(char **map);
int			cx_outerwall(char **map);
int			cx_maplimit(char **map);
int			cx_playable(char **map);

// cx_file_maps_3
int			cx_wall_upper(char **map, int y);
int			cx_wall_left(char **map, int x);
int			cx_wall_right(char **map, int x, int y);
int			cx_wall_lower(char **map, int x, int y);
int			recur_fill(char **map, int x, int y);

// cx_file_maps_4
int			map_env_counter(char **map, char c);
void		find_pos(char **map, char find, int *x, int *y);
int			count_width(char **map);
int			count_height(char **map);

// mapgen_1
void		mapgen(t_progwin *data);
void		to_print(char pos, int x, int y, t_progwin *data);
int			loop_window(t_progwin *data);

// keyhook_utils_1
int			key_hook(int key, t_progwin *data);
int			game_exit(t_progwin *data);
int			cx_wall(t_progwin *data, int x, int y);
void		moveto(t_progwin *data, int x, int y);
void		print_instruct(void);

// keyhook_utils_2



// error_handle
void		err_closefile_out(int fd, char *str);
void		err_with_msg(char *str);

#endif
