/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helped.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 16:24:31 by woumecht          #+#    #+#             */
/*   Updated: 2023/01/08 17:36:50 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPED_H
# define HELPED_H
# include <stdlib.h>
# include <unistd.h>

int		ft_strlen(char *str);
char	**ft_split(char const *s, char c);
char	*ft_strdup(char *str);
char	*ft_substr(char *s, int start, int len);

#endif