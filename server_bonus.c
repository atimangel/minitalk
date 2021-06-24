/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 14:27:02 by snpark            #+#    #+#             */
/*   Updated: 2021/06/22 19:54:00 by senoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static buffer_t buf_g;

void	handle_signal(int sig)
{
	buf_g.str[buf_g.count] = buf_g.str[buf_g.count] << 1;
	buf_g.i++;
	if (sig == SIGUSR2)
		buf_g.str[buf_g.count]++;
	if (buf_g.i == 8)
	{
		buf_g.i = 0;
		buf_g.count++;
	}
	kill(buf_g.pid, SIGUSR2);
	if (buf_g.count == buf_g.len)
	{
		write(1, (wchar_t *)buf_g.str, buf_g.len);
		write(1, "\n", 1);
		buf_g.i = 0;
		buf_g.len = 0;
		buf_g.count = 0;
		free(buf_g.str);
		buf_g.str = 0;
		buf_g.pid = 0;
		signal(SIGUSR1, recieve_pid);
		signal(SIGUSR2, recieve_pid);
	}
}

void		recieve_len(int sig)
{
	buf_g.len <<= 1;
	buf_g.i++;
	if (sig == SIGUSR2)
		buf_g.len++;
	if (buf_g.i == 32)
	{
		buf_g.i = 0;
		ft_putstr_fd("signal byte: ", 1);
		ft_putnbr(buf_g.len);
		write(1, "\n", 1);
		buf_g.str = (char *)malloc(buf_g.len);
		ft_bzero(buf_g.str, buf_g.len);
		signal(SIGUSR1, handle_signal);
		signal(SIGUSR2, handle_signal);
		usleep(100);
		kill(buf_g.pid, SIGUSR1);
	}
}

void		recieve_pid(int sig)
{
	buf_g.pid <<= 1;
	buf_g.i++;
	if (sig == SIGUSR2)
		buf_g.pid++;
	if (buf_g.i == 32)
	{
		buf_g.i = 0;
		if (kill(buf_g.pid, 0) == -1)
			error("recieved pid isn't significant\n");
		else
		{
			ft_putstr_fd("client PID: ");
			ft_putnbr(buf_g.pid);
			write(1, "\n", 1);
			usleep(100);
			kill(buf_g.pid, SIGUSR1);
		}
		signal(SIGUSR1, recieve_len);
		signal(SIGUSR2, recieve_len);
	}
}

int		main(void)
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
