/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 14:27:20 by snpark            #+#    #+#             */
/*   Updated: 2021/06/25 12:16:42 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void		server_status(int sig)
{
	if (sig == SIGUSR1)
		ft_putstr_fd("server recieved number\n", 1);
	if (sig == SIGUSR2)
		;
}

void		send(int pid, char *message)
{
	int		i;
	char	c;

	while (*message)
	{
		c = *message;
		i = 0;
		while (i < 8)
		{
			if ((c >> (7 - i)) % 2)
			{
				if (kill(pid, SIGUSR2) == -1)
					error("kill error\n");
			}
			else
			{
				if (kill(pid, SIGUSR1) == -1)
					error("kill error\n");
			}
			i++;
			pause();
			usleep(50);
		}
		message++;
	}
}

void		send_num(pid_t pid, int num)
{
	char len;

	ft_putstr_fd("send number ", 1);
	ft_putnbr(num);
	write(1, "\n", 1);
	len = 32;
	while (len)
	{
		if ((num >> 31) % 2)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(50);
		num = num << 1;
		len--;
	}
	pause();
	usleep(100);
}

int			main(int arg_i, char **arg_s)
{
	pid_t	pid;

	signal(SIGUSR1, server_status);
	signal(SIGUSR2, server_status);
	if (arg_i == 3)
	{
		pid = ft_atoi((char *)arg_s[1]);
		write(1, "\n", 1);
		if (kill(pid, 0) == -1)
			error("It's not significant PID\n");
		send_num(pid, getpid());
		send_num(pid, ft_strlen((char *)arg_s[2]));
		send(pid, (char *)arg_s[2]);
	}
	return (0);
}
