/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 10:21:57 by woumecht          #+#    #+#             */
/*   Updated: 2022/10/30 22:05:22 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len_src;
	size_t	len_dest;

	if (dst == NULL && dstsize == 0)
		return (ft_strlen(src));
	len_src = ft_strlen(src);
	len_dest = ft_strlen(dst);
	if (dstsize == 0 || len_dest >= dstsize)
		return (len_src + dstsize);
	i = 0;
	while (src[i] && i < dstsize - len_dest - 1)
	{
		dst[len_dest + i] = src[i];
		i++;
	}
	dst[len_dest + i] = '\0';
	return (len_src + len_dest);
}
