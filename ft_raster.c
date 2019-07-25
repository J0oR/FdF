/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gruocco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 19:47:32 by gruocco           #+#    #+#             */
/*   Updated: 2018/01/18 19:47:34 by gruocco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	ft_d_swapper(int *dx, int *dy, int *swap)
{
	if (abs(*dx) < abs(*dy))
	{
		ft_swap(dx, dy);
		*swap = 1;
	}
}

void	ft_color(t_point *p1, t_point *p2)
{
	if (p1->z != p2->z)
		p1->s_c = 0x44FF0000;
	if (p1->z == 0 && p2->z == 0)
		p1->s_c = 0x003399FF;
}

void	raster(t_point p1, t_point p2, t_data *data, int swap)
{
	int dx;
	int dy;
	int q;
	int s;
	int d;

	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	q = p1.x > p2.x ? -1 : 1;
	s = p1.y > p2.y ? -1 : 1;
	p1.k = 0;
	ft_d_swapper(&dx, &dy, &swap);
	d = 2 * abs(dy) + -abs(dx);
	mlx_pixel_put(data->x_ptr, data->x_win, p1.x + 250, p1.y + 550, p1.p_c);
	ft_color(&p1, &p2);
	while (p1.k++ < -(-abs(dx)))
	{
		p1.x += q;
		if (d > 0 || (d <= 0 && swap == 1))
			p1.y += s;
		if (d <= 0 && swap == 1)
			p1.x += -q;
		d = d > 0 ? d + 2 * (abs(dy) - abs(dx)) : d + 2 * abs(dy);
		mlx_pixel_put(data->x_ptr, data->x_win, p1.x + 250, p1.y + 550, p1.s_c);
	}
}

void	ft_raster_caller(t_utils *uty, t_data *data, t_point *pts)
{
	int i;
	int j;

	i = -1;
	while (++i < uty->lines_n - 1)
	{
		j = -1;
		while (++j < uty->line_s - 1)
			raster(pts[j + i * (uty->line_s)], pts[(j + 1) +
					i * (uty->line_s)], data, 0);
		j = -1;
		while (++j < uty->line_s)
			raster(pts[j + i * (uty->line_s)], pts[j +
					(i + 1) * (uty->line_s)], data, 0);
	}
	j = -1;
	while (++j < uty->line_s - 1)
		raster(pts[j + i * (uty->line_s)], pts[(j + 1) +
				i * (uty->line_s)], data, 0);
}
