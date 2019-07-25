/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coords.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gruocco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 19:21:33 by gruocco           #+#    #+#             */
/*   Updated: 2018/01/25 13:33:42 by gruocco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	ft_z_rot_vert(t_utils *uty, t_point *pts)
{
	int i;
	int j;

	i = -1;
	while (++i < uty->lines_n)
	{
		j = -1;
		while (++j < uty->line_s)
			pts[j + i * (uty->line_s)].y = -((j - i) * uty->l + 2 * pts[j +
					i * (uty->line_s)].z * uty->z_factor) / 2;
	}
}

void	ft_zoom_coord(t_utils *uty, t_point *pts)
{
	int i;
	int j;

	i = -1;
	while (++i < uty->lines_n)
	{
		j = -1;
		while (++j < uty->line_s)
		{
			pts[j + i * (uty->line_s)].x = (j + i) * uty->l;
			pts[j + i * (uty->line_s)].y = -((j - i) * uty->l +
					2 * pts[j + i * (uty->line_s)].z * uty->z_factor) / 2;
		}
	}
}
