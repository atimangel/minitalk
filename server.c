/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 14:27:02 by snpark            #+#    #+#             */
/*   Updated: 2021/06/25 11:52:22 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static t_char_buf g_buf;

void	handle_signal(int sig)
{
	g_buf.c = g_buf.c << 1;
	g_buf.i++;
	if (sig == SIGUSR2)
		g_buf.c++;
	if (g_buf.i == 8)
	{
		write(1, &g_buf.c, 1);
		g_buf.c = 0;
		g_buf.i = 0;
	}
}

int		main(void)
{
	pid_t		pid;

	if (signal(SIGUSR1, handle_signal) == SIG_ERR)
		error("signal handler setting error | SIGUSR1\n");
	if (signal(SIGUSR2, handle_signal) == SIG_ERR)
		error("signal handler setting error | SIGUSR2\n");
	pid = getpid();
	ft_putnbr(pid);
	write(1, "\n", 1);
	while (1)
		pause();
}
