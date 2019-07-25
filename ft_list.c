/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gruocco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 19:38:26 by gruocco           #+#    #+#             */
/*   Updated: 2018/01/18 19:38:28 by gruocco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

static int	ft_atoi_substr(char const *s, int j, char split, int i)
{
	int		words_num;
	int		word_begin;
	int		ret;
	char	*point_z;

	words_num = -1;
	while (s[i])
	{
		while (s[i] == split && s[i])
			i++;
		word_begin = i;
		if (s[i])
			words_num++;
		while (s[i] != split && s[i])
			i++;
		if (words_num == j)
		{
			point_z = (char *)ft_memalloc(sizeof(char) * (i - word_begin + 1));
			ft_strncpy(point_z, &s[word_begin], (size_t)i - word_begin);
			ret = ft_atoi(point_z);
			free(point_z);
			return (ret);
		}
	}
	return (0);
}

void		ft_fdffiller(int fd, t_utils *uty, t_point *pts, t_data *data)
{
	char		*line;
	int			i;
	int			j;
	int			z_factor;

	i = -1;
	z_factor = uty->z_factor == 1 ? uty->l : uty->z_factor;
	while (get_next_line(fd, &line) && ++i < uty->lines_n)
	{
		j = -1;
		while (++j < uty->line_s)
		{
			pts[j + (i * uty->line_s)].z = ft_atoi_substr(line, j, ' ', 0);
			pts[j + (i * uty->line_s)].s_c = 0x0066FF66;
			pts[j + (i * uty->line_s)].p_c = 0x00FFFFFF;
			pts[j + (i * uty->line_s)].x = (j + i) * uty->l;
			pts[j + (i * uty->line_s)].y = -((j - i) * uty->l + 2 * pts[j +
					(i * uty->line_s)].z * z_factor) / 2;
		}
		free(line);
	}
	ft_raster_caller(uty, data, pts);
}

static int	ft_words_counter(char *s, char split)
{
	int	words_num;
	int	i;

	words_num = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == split && s[i])
			i++;
		if (s[i])
			words_num++;
		while (s[i] != split && s[i])
			i++;
	}
	return (words_num);
}

int			ft_fdfreader(int fd, t_utils *uty, int len)
{
	char		*line;
	int			lines_n;
	int			line_s;
	int			flag;

	lines_n = 0;
	flag = 0;
	while (get_next_line(fd, &line))
	{
		if (flag++ == 0)
			len = ft_words_counter(line, ' ');
		line_s = ft_words_counter(line, ' ');
		if (len != line_s)
			return (0);
		lines_n++;
		free(line);
	}
	uty->lines_n = lines_n;
	uty->line_s = line_s;
	return (1);
}
