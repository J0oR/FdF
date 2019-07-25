/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gruocco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 18:42:52 by gruocco           #+#    #+#             */
/*   Updated: 2018/01/18 18:42:54 by gruocco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	ft_instructions(t_data *data)
{
	mlx_string_put(data->x_ptr, data->x_win, 20, 0, 0x00FFFFFF, "----------");
	mlx_string_put(data->x_ptr, data->x_win, 20, 20, 0x0000FF00, "zoom : + -");
	mlx_string_put(data->x_ptr, data->x_win, 20, 40, 0x00FFFFFF, "mv : arrows");
	mlx_string_put(data->x_ptr, data->x_win, 20, 60, 0x00FF0000, "z : w s");
	mlx_string_put(data->x_ptr, data->x_win, 20, 80, 0x0000FF00, "rot  : a d");
	mlx_string_put(data->x_ptr, data->x_win, 20, 100, 0x00FF0000, "ESC : exit");
	mlx_string_put(data->x_ptr, data->x_win, 20, 120, 0x00FFFFFF, "----------");
}

int		my_key_funct(int keycode, t_data *data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	ft_move(keycode, data, i, j);
	ft_rotate(keycode, data);
	ft_zoom(keycode, data);
	ft_z_factor(keycode, data);
	if (keycode == 53)
	{
		mlx_destroy_window(data->x_ptr, data->x_win);
		exit(0);
	}
	return (0);
}

void	ft_map(t_utils uty, t_data data, char **av)
{
	t_point		pts[uty.line_s * uty.lines_n];
	int			fd;

	uty.z_factor = 1;
	uty.l = uty.line_s / 3 > 25 ? 3 : 15;
	data.uty = &uty;
	fd = open(av[1], O_RDONLY);
	ft_fdffiller(fd, &uty, pts, &data);
	close(fd);
	data.pts = pts;
	ft_instructions(&data);
	mlx_key_hook(data.x_win, my_key_funct, &data);
	mlx_loop(data.x_ptr);
}

int		main(int ac, char **av)
{
	t_data		data;
	t_utils		uty;
	int			fd;

	data.uty = &uty;
	fd = open(av[1], O_RDONLY);
	if (ft_checks(&data, ac, av, fd))
		return (0);
	close(fd);
	ft_map(uty, data, av);
	return (1);
}
