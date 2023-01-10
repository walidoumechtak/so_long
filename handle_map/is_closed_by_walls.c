/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_closed_by_walls.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 06:02:42 by woumecht          #+#    #+#             */
/*   Updated: 2023/01/10 06:25:17 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_last_and_first(char *first, char *last)
{
	int	i;

	i = 0;
	while (first[i] && last[i])
	{
		if (first[i] != '1' || last[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	is_closed_by_walls(char *str)
{
	char	**arr;
	char	*l;
	int		last;
	int		length_line;
	int		i;

	arr = ft_split(str, '\n');
	last = 0;
	length_line = ft_strlen(arr[0]);
	while (arr[last + 1])
		last++;
	l = arr[last];
	if (check_last_and_first(arr[0], l) == 0)
		return (0);
	i = 0;
	while (arr[i + 1])
	{
		if (arr[i + 1][0] != '1' || arr[i + 1][length_line - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}
