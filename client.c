/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 21:41:08 by rde-fari          #+#    #+#             */
/*   Updated: 2024/09/10 15:25:13 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	string_encrypter(char *str, int pid)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(str);
	while (i <= len)
		char_encrypter(str[i++], pid);
}

void	char_encrypter(int c, int pid)
{
	int		i;

	i = 0;
	while (i < 8)
	{
		if (c % 2 != 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		c /= 2;
		i++;
		usleep(250);
	}
}

int	main(int argc, char *argv[])
{
	int		pid;

	if (argc != 3)
	{
		ft_printf("Invalid number of arguments!\n");
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	string_encrypter(argv[2], pid);
	return (0);
}
