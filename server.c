/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 14:27:02 by snpark            #+#    #+#             */
/*   Updated: 2021/06/22 19:29:11 by senoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

static char c;
static int 	i;

void	handle_signal(int sig)
{
	c = c << 1;
	i++;
	if (sig == SIGUSR2)
		c++;
	if (i == 8)
	{
		write(1, &c, 1);
		c = 0;
		i = 0;
	}
}

int		main(void)
{
	pid_t		pid;
	struct sigaction act;

	act.sa_flags = SA_NODEFER;
	act.sa_handler = handle_signal;
	sigaction(SIGUSR1, &act, 0);
	sigaction(SIGUSR2, &act, 0);
	pid = getpid();
	ft_putnbr(pid);
	write(1, "\n", 1);
	while (1)
		pause();
}
