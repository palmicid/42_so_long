/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 10:40:49 by pruangde          #+#    #+#             */
/*   Updated: 2022/11/01 10:40:52 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	err_closefile_out(int fd, char *str)
{
	if (str)
		ft_putendl_fd(str, 2);
	if (fd != -1)
		close(fd);
	exit(EXIT_FAILURE);
}

void	err_with_msg(char *str)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(str, 2);
}
