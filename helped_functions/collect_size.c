/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:22:38 by woumecht          #+#    #+#             */
/*   Updated: 2023/01/15 08:41:20 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	collect_size(t_long *ptr)
{
	int	i;
	int	j;
	int	cpt;

	i = 0;
	cpt = 0;
	while (ptr->arr[i])
	{
		j = 0;
		while (ptr->arr[i][j])
		{
			if (ptr->arr[i][j] == 'C')
				cpt++;
			j++;
		}
		i++;
	}
	return (cpt);
}
