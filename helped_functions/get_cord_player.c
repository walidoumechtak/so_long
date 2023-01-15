/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cord_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:26:13 by woumecht          #+#    #+#             */
/*   Updated: 2023/01/15 08:43:03 by woumecht         ###   ########.fr       */
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
				return ;
			}
			j++;
		}
		i++;
	}
}
