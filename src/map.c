/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 13:29:47 by dsamarsk          #+#    #+#             */
/*   Updated: 2019/04/09 17:21:32 by rzero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fillit.h"

void	print_map(t_map *map)
{
	int	x;
	int	y;

	x = map->min_x;
	y = map->min_y;
	while (y <= map->max_y)
	{
		ft_putstr(map->map[y]);
		ft_putchar('\n');
		y++;
	}
}

t_map	*re_cr_map(t_map *map, int size)
{
	int		yr;
	t_map	*nm;

	yr = 0;
	nm = (t_map *)ft_memalloc(sizeof(t_map));
	nm->min_x = 0;
	nm->min_y = 0;
	nm->max_y = ft_sqrt(size * 4) - 1;
	nm->max_x = nm->max_y;
	nm->map = (char **)ft_memalloc(sizeof(char *) * (nm->max_y + 1));
	while (yr <= nm->max_y)
	{
		nm->map[yr] = (char*)ft_strnew(sizeof(char) * (nm->max_x + 1));
		ft_memset(nm->map[yr], '.', nm->max_x + 1);
		ft_memdel((void **)&(map->map[yr]));
		yr++;
	}
	ft_memdel((void **)&(map->map));
	ft_memdel((void **)&map);
	return (nm);
}

void	cr_map(t_map *map, int count_tetremin)
{
	int	ym;

	ym = 0;
	map->min_x = 0;
	map->min_y = 0;
	map->max_y = ft_sqrt(count_tetremin * 4) - 1;
	map->max_x = map->max_y;
	map->map = (char**)ft_memalloc(sizeof(char*) * (map->max_y + 1));
	while (ym <= map->max_y)
	{
		map->map[ym] = (char*)ft_strnew(sizeof(char) * (map->max_x + 1));
		ft_memset(map->map[ym], '.', map->max_x + 1);
		ym++;
	}
}
