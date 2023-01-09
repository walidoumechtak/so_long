/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:27:53 by woumecht          #+#    #+#             */
/*   Updated: 2022/11/02 08:10:23 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isexist(char c, char *p)
{
	int	i;

	i = 0;
	while (p[i] != '\0')
	{
		if (c == p[i])
			return (1);
		i++;
	}
	return (0);
}

static int	ft_start(char *s1, char *set)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (ft_isexist(s1[i], set) == 1)
			i++;
		else if (ft_isexist(s1[i], set) == 0)
			break ;
	}
	return (i);
}

static int	ft_end(char *s1, int len, char *set)
{
	int	j;

	j = len;
	while (j >= 0)
	{
		if (ft_isexist(s1[j], set) == 1)
			j--;
		else if (ft_isexist(s1[j], set) == 0)
			break ;
	}
	return (j);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	int		len;
	int		start;
	int		end;

	if (s1 == NULL || set == NULL)
		return (NULL);
	if (s1[0] == '\0')
		return (ft_strdup(""));
	len = ft_strlen(s1) - 1;
	start = ft_start((char *) s1, (char *) set);
	end = ft_end((char *) s1, len, (char *) set);
	if (start > end)
		return (ft_strdup(""));
	trim = ft_substr(s1, start, len - start - (len - end) + 1);
	return (trim);
}
