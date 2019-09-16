/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 19:03:48 by dsamarsk          #+#    #+#             */
/*   Updated: 2019/04/09 18:03:59 by dsamarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "../libft/libft.h"
# include <fcntl.h>
# define ARGC_ERR "usage: ./fillit source_file\n"
# define FILE_ERR "error\n"
# define OPEN_ERR "Unable to open file.\n"
# define CLOSE_ERR "Unable to close file.\n"

typedef struct	s_tetr
{
	char		**tetremin;
	char		letter;
	int			x[4];
	int			y[4];
}				t_tetr;

typedef struct	s_map
{
	char		**map;
	int			max_x;
	int			max_y;
	int			min_x;
	int			min_y;
}				t_map;

typedef struct	s_valid
{
	char		**array;
	int			x;
	int			y;
	int			dote;
	int			hash;
	int			neighbors;
	int			newline;
	int			count_tetr;
}				t_valid;

int				read_file(const int fd);
int				validator(const int fd, char *buffer, t_valid *v);
int				enable_validator(char *buffer, t_valid *v);
int				valid_symbol_and_newline(t_valid *v);
void			valid_tetremin(t_valid *v);
int				cr_tetremin(const char *file, t_tetr *t, int count_tetremin);
void			tetremin(t_tetr *t, char *buffer);
void			set_coords(t_tetr *t);
void			cr_map(t_map *map, int count_tetremin);
void			print_map(t_map *map);
t_map			*re_cr_map(t_map *map, int size);
int				backtracking(t_tetr *t, t_map *map, int count_tetremin);
int				enable_backtracking(t_tetr *t, t_map *map, int id, int c_t);
int				place_tetremin(t_tetr *t, t_map *map, int yb, int xb);
t_map			*clear_map(t_tetr *t, t_map *map);
int				finde_place(t_tetr *t, t_map *map, int yb, int xb);
void			catch_err(int id);
void			ft_arraydel(char **ar);
int				ft_sqrt(int nb);

#endif
