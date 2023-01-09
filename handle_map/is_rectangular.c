/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_rectangular.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:09:55 by woumecht          #+#    #+#             */
/*   Updated: 2023/01/09 20:51:50 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_s(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
}

int	is_rectangular(char *str)
{
	char	**s;
	int		i;
	int		j;
	int		n1;
	int		n2;

	s = ft_split(str, '\n');
	i = 0;
	j = 0;
	while (s[j])
		j++;
	while (i < j - 1)
	{
		n1 = ft_strlen(s[i]);
		n2 = ft_strlen(s[i + 1]);
		if (n1 != n2)
		{
			free_s(s);
			free(s);
			return (0);
		}
		i++;
	}
	free_s(s);
	free(s);
	return (1);
}
