/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cord_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:26:13 by woumecht          #+#    #+#             */
/*   Updated: 2023/01/14 08:49:19 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	get_cord_palyer(t_long *ptr)
{
	int	i;
	int	j;

	i = 0;
	while (ptr->arr[i])
	{
		j = 0;
		while (ptr->arr[i][j])
		{
			if (ptr->arr[i][j] == 'P')
			{
				ptr->p.y = j;
				ptr->p.z = i;
				ptr->f->y1 = j;
				ptr->f->z2 = i;
				return ;
			}
			j++;
		}
		i++;
	}
}