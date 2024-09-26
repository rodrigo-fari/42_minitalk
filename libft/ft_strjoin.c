/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42poto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:51:27 by rde-fari          #+#    #+#             */
/*   Updated: 2024/08/28 11:52:06 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, char s2)
{
	char			*strjoin;
	size_t			malloc_size;
	size_t			i;

	malloc_size = ((ft_strlen(s1) + ft_strlen(&s2)) + 1);
	strjoin = ft_calloc(sizeof(char), malloc_size);
	if (!strjoin)
		return (NULL);
	i = 0;
	while (i < (ft_strlen((const char *)s1)))
	{
		strjoin[i] = s1[i];
		i++;
	}
	strjoin[i] = s2;
	i++;
	strjoin[i] = '\0';
	return (strjoin);
}
