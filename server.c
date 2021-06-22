/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 14:27:02 by snpark            #+#    #+#             */
/*   Updated: 2021/06/22 19:40:44 by senoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static char_buf_t buf

void	handle_signal(int sig)
{
	buf.c = buf.c << 1;
	buf.i++;
	if (sig == SIGUSR2)
		buf.c++;
	if (i == 8)
	{
		write(1, &buf.c, 1);
		buf.c = 0;
		buf.i = 0;
	}
}

int		main(void)
{
	pid_t		pid;

	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	pid = getpid();
	ft_putnbr(pid);
	write(1, "\n", 1);
	while (1)
		pause();
}
