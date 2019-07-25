/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gruocco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 18:57:50 by gruocco           #+#    #+#             */
/*   Updated: 2018/01/18 18:57:52 by gruocco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int		ft_checks(t_data *data, int ac, char **av, int fd)
{
	int len;

	len = 0;
	if (ac != 2)
	{
		ft_putendl("Usage : ./demo_fdf <filename>");
		return (1);
	}
	if (fd < 0)
	{
		ft_putstr("No file ");
		ft_putendl(av[1]);
		return (1);
	}
	if (!ft_fdfreader(fd, data->uty, len))
	{
		ft_putendl("Found wrong line length. Exiting.");
		return (1);
	}
	if ((data->x_ptr = mlx_init()) == NULL)
		return (1);
	if ((data->x_win = mlx_new_window(data->x_ptr, 2200, 1400, "X")) == NULL)
		return (1);
	return (0);
}
