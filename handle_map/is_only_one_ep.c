/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_only_one_ep.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:20:56 by woumecht          #+#    #+#             */
/*   Updated: 2023/01/15 08:31:19 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	is_only_one_p_e(t_long *ptr)
{
	int	i;
	int	j;

	i = 0;
	while (ptr->arr[i])
	{
		j = 0;
		while (ptr->arr[i][j])
		{
			if (ptr->arr[i][j] == 'E')
				ptr->e_count++;
			else if (ptr->arr[i][j] == 'P')
				ptr->p_count++;
			else if (ptr->arr[i][j] == 'C')
				ptr->c_count++;
			j++;
		}
		if (ptr->e_count > 1 || ptr->p_count > 1)
			return (0);
		i++;
	}
	if (ptr->c_count == 0)
		return (0);
	return (1);
}
