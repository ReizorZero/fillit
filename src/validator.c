/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 21:01:06 by dsamarsk          #+#    #+#             */
/*   Updated: 2019/04/09 17:53:50 by dsamarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fillit.h"

void	valid_tetremin(t_valid *v)
{
	v->y = 0;
	while (v->y <= 3)
	{
		v->x = 0;
		while (v->x <= 3)
		{
			if (v->array[v->y][v->x] == '#')
			{
				if (v->y != 0 && v->array[v->y - 1][v->x] == '#')
					v->neighbors++;
				if (v->y != 3 && v->array[v->y + 1][v->x] == '#')
					v->neighbors++;
				if (v->x != 0 && v->array[v->y][v->x - 1] == '#')
					v->neighbors++;
				if (v->x != 3 && v->array[v->y][v->x + 1] == '#')
					v->neighbors++;
				v->x++;
			}
			else
				v->x++;
		}
		v->y++;
	}
}

int		valid_symbol_and_newline(t_valid *v)
{
	v->y = 0;
	while (v->array[v->y])
	{
		if ((ft_strlen(v->array[v->y])) != 4 && v->y > 3)
			return (0);
		v->x = 0;
		while (v->array[v->y][v->x])
		{
			if (v->array[v->y][v->x] == '.')
			{
				v->x++;
				v->dote++;
			}
			else if (v->array[v->y][v->x] == '#')
			{
				v->x++;
				v->hash++;
			}
			else
				return (0);
		}
		v->y++;
	}
	return (1);
}

int		enable_validator(char *buffer, t_valid *v)
{
	v->array = ft_strsplit(buffer, '\n');
	v->dote = 0;
	v->hash = 0;
	v->neighbors = 0;
	if ((valid_symbol_and_newline(v)) == 1)
	{
		if (v->dote == 12 && v->hash == 4)
		{
			valid_tetremin(v);
			if (v->neighbors == 6 || v->neighbors == 8)
				return (1);
		}
		else
			return (0);
	}
	return (0);
}

int		validator(const int fd, char *buffer, t_valid *v)
{
	int		read_bytes;

	ft_bzero(buffer, 21);
	while ((read_bytes = read(fd, buffer, 21)) > 0)
	{
		if (read_bytes < 20)
			return (0);
		buffer[read_bytes] = '\0';
		if ((enable_validator(buffer, v)) == 1)
			v->count_tetr++;
		if (buffer[20] == '\n')
			v->newline++;
		ft_arraydel(v->array);
	}
	if (v->newline != (v->count_tetr - 1))
		return (0);
	return (1);
}

int		read_file(const int fd)
{
	char		buffer[22];
	t_valid		*v;
	int			count;

	if (fd < 0 || (read(fd, buffer, 0)) < 0)
		catch_err(3);
	v = (t_valid *)ft_memalloc(sizeof(t_valid));
	v->newline = 0;
	v->count_tetr = 0;
	if (validator(fd, buffer, v) == 0)
	{
		ft_bzero(buffer, 22);
		ft_memdel((void **)&v);
		return (0);
	}
	if (v->count_tetr > 26)
		return (0);
	count = v->count_tetr;
	ft_bzero(buffer, 22);
	ft_memdel((void **)&v);
	if ((close(fd)) == -1)
		catch_err(4);
	return (count);
}
