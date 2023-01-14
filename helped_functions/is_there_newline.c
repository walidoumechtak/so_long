/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_there_newline.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 11:43:35 by woumecht          #+#    #+#             */
/*   Updated: 2023/01/14 11:52:48 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	is_there_newline(t_long *ptr)
{
	int i;
	int j;

	i = 0;
	while (ptr->arr[i])
	{
		j = 0;
		while (ptr->arr[i][j])
		{
			if (ptr->arr[i][j] == '\n')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}