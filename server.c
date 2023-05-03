/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misi-moh <misi-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 14:58:06 by misi-moh          #+#    #+#             */
/*   Updated: 2023/05/03 16:08:24 by misi-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_handel(int signal, siginfo_t *info, void *content)
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


void    signal_conf(void)
{
    struct sigaction    newsig;
    newsig.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &newsig, NULL) < 0)
		write(1, "Failed to change SIGUSR1", 25);
	if (sigaction(SIGUSR2, &newsig, NULL) < 0)
		write(1, "Failed to change SIGUSR2", 25);
}



int main(void)
{
    int pid_server;

    pid_server = get_pid();
    printf("SERVER PID: %d\n\n", pid_server);
    while (1)
        signal_conf();
    return (0);
}