/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extenstion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:50:55 by woumecht          #+#    #+#             */
/*   Updated: 2023/01/28 20:14:16 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_freeing(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		free(s[i++]);
	free(s);	
}

int	check_extenstion(char **av)
{
	char	**s;
	int		i;

	i = 0;
	s = ft_split(av[1], '.');
	while (s[1][i])
	{
		if (s[1][i] != 'b' && s[1][i] != 'e' && s[1][i] != 'r')
		{
			ft_freeing(s);
			return (0);
		}
		i++;
	}
	ft_freeing(s);
	return (1);
}
