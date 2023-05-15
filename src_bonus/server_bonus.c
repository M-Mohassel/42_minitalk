/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misi-moh <misi-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:37:31 by misi-moh          #+#    #+#             */
/*   Updated: 2023/05/15 12:11:05 by misi-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	sig_handle(int signal, siginfo_t *info, void *content)
{
	static int				bits;
	static unsigned char	c;

	(void)info;
	(void)content;
	if (signal == SIGUSR1)
		c |= 1 << (7 - bits);
	bits++;
	if (bits == 8)
	{
		ft_putchar_fd(c, STDOUT_FILENO);
		if (c == '\0')
			kill(info->si_pid, SIGUSR2);
		c = 0;
		bits = 0;
	}
}

void	signal_conf(void)
{
	struct sigaction	newsig;

	newsig.sa_sigaction = &sig_handle;
	newsig.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &newsig, NULL) < 0)
		write(1, "Failed to change SIGUSR1", 25);
	if (sigaction(SIGUSR2, &newsig, NULL) < 0)
		write(1, "Failed to change SIGUSR2", 25);
}

int	main(void)
{
	int	pid_server;

	pid_server = getpid();
	printf("SERVER PID: %d\n\n", pid_server);
	signal_conf();
	while (1)
	{
		pause();
	}
	return (0);
}
