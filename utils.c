/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42poto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 21:42:17 by rde-fari          #+#    #+#             */
/*   Updated: 2024/10/02 10:13:37 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*mod_strjoin(char *str, char c)
{
	size_t	i;
	size_t	j;
	size_t	size;
	char	*temp_str;

	i = 0;
	j = 0;
	size = 0;
	if (str)
		size = ft_strlen(str);
	temp_str = NULL;
	size = size + 1;
	temp_str = malloc(sizeof(char) * (size + 1));
	if (!temp_str)
		return (NULL);
	if (str)
	{
		while (str[i])
			temp_str[j++] = str[i++];
		if (str)
			free(str);
	}
	temp_str[j++] = c;
	temp_str[j] = '\0';
	return (temp_str);
}
