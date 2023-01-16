/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_5_comp_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:14:32 by woumecht          #+#    #+#             */
/*   Updated: 2023/01/16 14:28:40 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	is_5_bonus(char c)
{
	if ((c == '0') || c == '1' || c == 'C' || c == 'E' || c == 'P' || c == '\n')
		return (1);
	return (0);
}

int	is_5_comp_bonus(char *string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (is_5_bonus(string[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}
