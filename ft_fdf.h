/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gruocco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 18:14:30 by gruocco           #+#    #+#             */
/*   Updated: 2018/01/18 18:14:32 by gruocco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "minilibx_macos/mlx.h"
# include "libft/libft.h"

typedef struct	s_point
{
	int		z;
	int		x;
	int		y;
	int		k;
	int		p_c;
	int		s_c;
}				t_point;

typedef struct	s_utils
{
	int	lines_n;
	int	line_s;
	int l;
	int z_factor;
}				t_utils;

typedef struct	s_data
{
	void		*x_ptr;
	void		*x_win;
	t_utils		*uty;
	t_point		*pts;
}				t_data;

void			ft_instructions(t_data *data);
int				ft_checks(t_data *data, int ac, char **av, int fd);

void			ft_z_rot_vert(t_utils *uty, t_point *pts);
void			ft_zoom_coord(t_utils *uty, t_point *pts);

int				ft_move(int keycode, t_data *data, int i, int j);
int				ft_zoom(int keycode, t_data *data);
int				ft_rotate(int keycode, t_data *data);
int				ft_z_factor(int keycode, t_data *data);

void			ft_raster_caller(t_utils *uty, t_data *data, t_point *pts);

void			ft_fdffiller(int fd, t_utils *uty, t_point *pts, t_data *data);
int				ft_fdfreader(int fd, t_utils *uty, int len);

#endif
