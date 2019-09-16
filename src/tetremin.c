/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetremin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 19:05:23 by dsamarsk          #+#    #+#             */
/*   Updated: 2019/04/09 17:15:10 by rzero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fillit.h"

void	tetremin(t_tetr *t, char *buffer)
{
	int		xt;
	int		yt;
	int		i;

	i = 0;
	yt = 0;
	t->tetremin = ft_strsplit(buffer, '\n');
	while (t->tetremin[yt])
	{
		xt = 0;
		while (t->tetremin[yt][xt])
		{
			if (t->tetremin[yt][xt] == '#')
			{
				t->x[i] = xt;
				t->y[i] = yt;
				xt++;
				i++;
			}
			else
				xt++;
		}
		yt++;
	}
}

void	set_coords(t_tetr *t)
{
	int		i;
	int		d_x;
	int		d_y;

	i = 0;
	d_x = t->x[0];
	d_y = t->y[0];
	if (t->x[0] > t->x[2])
		d_x = t->x[2];
	if (t->x[0] > t->x[1])
		d_x = t->x[1];
	while (i <= 3)
	{
		t->x[i] = t->x[i] - d_x;
		t->y[i] = t->y[i] - d_y;
		i++;
	}
}

int		cr_tetremin(const char *file, t_tetr *t, int count_tetremin)
{
	char		buffer[22];
	int			read_bytes;
	int			id;
	int			fd;

	fd = open(file, O_RDONLY);
	if (fd < 0 || (read(fd, buffer, 0)) < 0)
		catch_err(3);
	id = 0;
	t[id].letter = 'A';
	while ((read_bytes = read(fd, buffer, 21)) > 0)
	{
		buffer[read_bytes] = '\0';
		tetremin(&t[id], buffer);
		set_coords(&t[id]);
		if (id + 1 >= count_tetremin)
			break ;
		id++;
		t[id].letter = 'A' + id;
	}
	return (1);
}
