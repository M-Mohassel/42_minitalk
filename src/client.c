/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misi-moh <misi-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 14:57:54 by misi-moh          #+#    #+#             */
/*   Updated: 2023/05/06 15:22:01 by misi-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int	g_signal_received;

void	send_null(int pid_server)
{
	int		bits;
	char	null;

	bits = 8;
	null = '\0';
	while (bits)
	{
		if (null & 10000000)
			kill(pid_server, SIGUSR1);
		else
			kill(pid_server, SIGUSR2);
		usleep (100);
		null <<= 1;
		bits--;
	}
}

void	send_bits(pid_t pid_server, char *message)
{
	unsigned char	c;
	int				bits;

	while (*message)
	{
		c = *message;
		bits = 8;
		while (bits)
		{
			if (c & 10000000)
				kill(pid_server, SIGUSR1);
			else
				kill(pid_server, SIGUSR2);
			usleep(100);
			c <<= 1;
			bits--;
		}
		message++;
	}
}

void	sig_modify(int sig_number)
{
	if (sig_number == SIGUSR2)
		ft_printf("Message has been received!\n");
	g_signal_received = 1;
}

void	config_signals(void)
{
	struct sigaction	newsig;

	newsig.sa_handler = &sig_modify;
	newsig.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &newsig, NULL) < 0)
		ft_printf("Failed to change SIGUSR1");
	if (sigaction(SIGUSR2, &newsig, NULL) < 0)
		ft_printf("Failed to change SIGUSR2");
}

int	main(int av, char	*ag[])
{
	pid_t	pid_server;
	int		i;

	i = 0;
	if (av != 3)
		return (1);
	while (ag[1][i])
		if (!ft_isdigit(ag[1][i++]))
			return (1);
	pid_server = ft_atoi(ag[1]);
	config_signals();
	send_bits(pid_server, ag[2]);
	send_bits(pid_server, "\n");
	send_null(pid_server);
	while (1)
	{
		if (g_signal_received)
			exit(0);
		pause ();
	}
	return (0);
}
