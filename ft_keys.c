/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gruocco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 21:49:04 by gruocco           #+#    #+#             */
/*   Updated: 2018/01/20 21:49:05 by gruocco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int		ft_move(int keycode, t_data *data, int i, int j)
{
	int side;
	int vertical;

	if (keycode == 126 || keycode == 125 || keycode == 123 || keycode == 124)
	{
		i = -1;
		side = (keycode == 123) ? -40 : 40;
		vertical = (keycode == 126) ? -40 : 40;
		while (++i < data->uty->lines_n)
		{
			j = -1;
			while (++j < data->uty->line_s)
			{
				if (keycode == 126 || keycode == 125)
					data->pts[j + i * (data->uty->line_s)].y += vertical;
				if (keycode == 123 || keycode == 124)
					data->pts[j + i * (data->uty->line_s)].x += side;
			}
		}
		mlx_clear_window(data->x_ptr, data->x_win);
		ft_instructions(data);
		ft_raster_caller(data->uty, data, data->pts);
		return (0);
	}
	return (1);
}

int		ft_rotate(int keycode, t_data *data)
{
	int z;

	if (keycode == 0 || keycode == 2)
	{
		z = (keycode == 0) ? 1 : -1;
		data->uty->l += z;
		ft_z_rot_vert(data->uty, data->pts);
		mlx_clear_window(data->x_ptr, data->x_win);
		ft_instructions(data);
		ft_raster_caller(data->uty, data, data->pts);
		return (0);
	}
	return (1);
}

int		ft_zoom(int keycode, t_data *data)
{
	int zoom;

	if (keycode == 69 || keycode == 78)
	{
		zoom = (keycode == 69) ? 1 : -1;
		data->uty->l += zoom;
		if (data->uty->l > 0)
		{
			ft_zoom_coord(data->uty, data->pts);
			mlx_clear_window(data->x_ptr, data->x_win);
			ft_instructions(data);
			ft_raster_caller(data->uty, data, data->pts);
			return (0);
		}
	}
	return (1);
}

int		ft_z_factor(int keycode, t_data *data)
{
	int z_factor;

	if (keycode == 13 || keycode == 1)
	{
		z_factor = (keycode == 13) ? 1 : -1;
		data->uty->z_factor += z_factor;
		ft_zoom_coord(data->uty, data->pts);
		mlx_clear_window(data->x_ptr, data->x_win);
		ft_instructions(data);
		ft_raster_caller(data->uty, data, data->pts);
		return (0);
	}
	return (1);
}
