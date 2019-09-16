/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraydel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 20:58:32 by dsamarsk          #+#    #+#             */
/*   Updated: 2019/04/09 16:59:44 by rzero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fillit.h"

void	ft_arraydel(char **ar)
{
	int	i;

	i = 0;
	while (ar && ar[i] != NULL)
	{
		ft_strdel(&ar[i]);
		i++;
	}
	free(ar);
}
