/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 18:38:15 by dsamarsk          #+#    #+#             */
/*   Updated: 2019/04/09 17:12:01 by rzero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fillit.h"

void	catch_err(int id)
{
	if (id == 1)
	{
		ft_putstr(ARGC_ERR);
		exit(1);
	}
	else if (id == 2)
	{
		ft_putstr(FILE_ERR);
		exit(2);
	}
	else if (id == 3)
	{
		ft_putstr(OPEN_ERR);
		exit(3);
	}
	else if (id == 4)
	{
		ft_putstr(CLOSE_ERR);
		exit(4);
	}
}
