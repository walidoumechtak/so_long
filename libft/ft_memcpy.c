/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 09:46:07 by woumecht          #+#    #+#             */
/*   Updated: 2022/10/31 11:20:29 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const char	*sr;
	char		*p;
	size_t		i;

	if (dst == NULL && src == NULL)
		return (NULL);
	sr = src;
	p = dst;
	if (p == sr)
		return (p);
	i = 0;
	while (i < n)
	{
		p[i] = sr[i];
		i++;
	}
	return (dst);
}
