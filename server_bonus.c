/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 14:27:02 by snpark            #+#    #+#             */
/*   Updated: 2021/06/25 12:21:28 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static t_buffer g_buf;

void		handle_signal(int sig)
{
	g_buf.str[g_buf.count] = g_buf.str[g_buf.count] << 1;
	g_buf.i++;
	if (sig == SIGUSR2)
		g_buf.str[g_buf.count]++;
	if (g_buf.i == 8)
	{
		g_buf.i = 0;
		g_buf.count++;
	}
	kill(g_buf.pid, SIGUSR2);
	if (g_buf.count == g_buf.len)
	{
		write(1, g_buf.str, g_buf.len);
		write(1, "\n", 1);
		g_buf.i = 0;
		g_buf.len = 0;
		g_buf.count = 0;
		free(g_buf.str);
		g_buf.str = 0;
		g_buf.pid = 0;
		signal(SIGUSR1, recieve_pid);
		signal(SIGUSR2, recieve_pid);
	}
}

void		recieve_len(int sig)
{
	g_buf.len <<= 1;
	g_buf.i++;
	if (sig == SIGUSR2)
		g_buf.len++;
	if (g_buf.i == 32)
	{
		g_buf.i = 0;
		ft_putstr_fd("signal byte: ", 1);
		ft_putnbr(g_buf.len);
		write(1, "\n", 1);
		g_buf.str = (char *)malloc(g_buf.len);
		ft_bzero(g_buf.str, g_buf.len);
		signal(SIGUSR1, handle_signal);
		signal(SIGUSR2, handle_signal);
		usleep(100);
		kill(g_buf.pid, SIGUSR1);
	}
}

void		recieve_pid(int sig)
{
	g_buf.pid <<= 1;
	g_buf.i++;
	if (sig == SIGUSR2)
		g_buf.pid++;
	if (g_buf.i == 32)
	{
		g_buf.i = 0;
		if (kill(g_buf.pid, 0) == -1)
			error("recieved pid isn't significant\n");
		else
		{
			ft_putstr_fd("client PID: ", 1);
			ft_putnbr(g_buf.pid);
			write(1, "\n", 1);
			usleep(100);
			kill(g_buf.pid, SIGUSR1);
		}
		signal(SIGUSR1, recieve_len);
		signal(SIGUSR2, recieve_len);
	}
}

int			main(void)
{
	pid_t		pid;

	signal(SIGUSR1, recieve_pid);
	signal(SIGUSR2, recieve_pid);
	pid = getpid();
	ft_putnbr(pid);
	write(1, "\n", 1);
	while (1)
		pause();
}
