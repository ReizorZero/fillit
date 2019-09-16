/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 18:10:56 by dsamarsk          #+#    #+#             */
/*   Updated: 2019/04/09 17:19:50 by rzero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fillit.h"

t_map	*clear_map(t_tetr *t, t_map *map)
{
	int	xm;
	int	ym;

	ym = 0;
	while (ym <= map->max_y)
	{
		xm = 0;
		while (xm <= map->max_x)
		{
			if (map->map[ym][xm] == t->letter)
				map->map[ym][xm] = '.';
			xm++;
		}
		ym++;
	}
	return (map);
}

int		finde_place(t_tetr *t, t_map *map, int yb, int xb)
{
	int		i;
	int		d_x;
	int		d_y;

	i = 0;
	while (i <= 3)
	{
		d_x = t->x[i] + xb;
		d_y = t->y[i] + yb;
		if (d_x > map->max_x || d_y > map->max_y)
			return (0);
		if (map->map[d_y][d_x] != '.')
			return (0);
		i++;
	}
	return (1);
}

int		placed_tetremin(t_tetr *t, t_map *map, int yb, int xb)
{
	int		i;

	i = 0;
	while (i <= 3)
	{
		map->map[t->y[i] + yb][t->x[i] + xb] = t->letter;
		i++;
	}
	return (1);
}

int		enable_backtracking(t_tetr *t, t_map *map, int id, int count_tetremin)
{
	int	xb;
	int	yb;

	if (id >= count_tetremin)
		return (1);
	yb = 0;
	while (yb <= map->max_y)
	{
		xb = 0;
		while (xb <= map->max_x)
		{
			if (finde_place(&t[id], map, yb, xb))
			{
				placed_tetremin(&t[id], map, yb, xb);
				if (enable_backtracking(t, map, (id + 1), count_tetremin) != 0)
					return (1);
				else
					clear_map(&t[id], map);
			}
			xb++;
		}
		yb++;
	}
	return (0);
}

int		backtracking(t_tetr *t, t_map *map, int count_tetremin)
{
	int id;
	int	size;
	int i;

	i = 0;
	size = count_tetremin;
	id = 0;
	while (enable_backtracking(t, map, id, count_tetremin) == 0)
	{
		size++;
		map = re_cr_map(map, size);
	}
	print_map(map);
	while (map && i <= map->max_y)
		ft_memdel((void **)&(map->map[i++]));
	ft_memdel((void **)&(map->map));
	ft_memdel((void **)&map);
	return (1);
}
