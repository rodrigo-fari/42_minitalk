/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 21:41:31 by rde-fari          #+#    #+#             */
/*   Updated: 2024/09/26 19:36:19 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static char	*g_buffer;

void	sig_handler(int sig_ident)
{
	static int		i;
	static int		bin[8];

	if (sig_ident == SIGUSR1)
		bin[i] = 0;
	else
		bin[i] = 1;
	i++;
	if (i == 8)
	{
		char_dencrypter(bin);
		i = 0;
	}
}

void	char_dencrypter(int *bin)
{
	int		i;
	char	result;

	i = 8;
	result = 0;
	while (i >= 0)
	{
		result = (result * 2) + bin[i--];
	}
	g_buffer = mod_strjoin(g_buffer, result);
	if (result == '\0')
	{
		ft_printf("%s\n", g_buffer);
		free(g_buffer);
		g_buffer = NULL;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("PID: %d\n", pid);
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	while (true)
		pause();
	return (0);
}
