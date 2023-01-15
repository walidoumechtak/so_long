/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 10:08:17 by woumecht          #+#    #+#             */
/*   Updated: 2023/01/15 08:40:17 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_path(t_long *ptr)
{
	int	i;
	int	j;
	int	count_c;
	int	count_e;

	i = 0;
	count_c = 0;
	count_e = 0;
	while (ptr->flood_arr[i])
	{
		j = 0;
		while (ptr->flood_arr[i][j])
		{
			if (ptr->flood_arr[i][j] == 'E')
				count_e++;
			else if (ptr->flood_arr[i][j] == 'C')
				count_c++;
			j++;
		}
		i++;
	}
	if (count_e > 0 || count_c > 0)
		return (0);
	return (1);
}
