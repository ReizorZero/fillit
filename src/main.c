/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 18:19:37 by dsamarsk          #+#    #+#             */
/*   Updated: 2019/04/09 17:48:00 by dsamarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fillit.h"

int	main(int argc, char **argv)
{
	int		fd;
	int		count_tetremin;
	t_tetr	*t;
	t_map	*map;

	if (argc != 2)
		catch_err(1);
	else
	{
		fd = open(argv[1], O_RDONLY);
		if ((count_tetremin = read_file(fd)) > 0)
		{
			t = (t_tetr *)ft_memalloc(sizeof(t_tetr) * (count_tetremin + 1));
			map = (t_map *)ft_memalloc(sizeof(t_map));
			cr_tetremin(argv[1], t, count_tetremin);
			cr_map(map, count_tetremin);
			backtracking(t, map, count_tetremin);
		}
		else
			catch_err(2);
		if (close(fd) == -1)
			catch_err(4);
	}
	return (0);
}
