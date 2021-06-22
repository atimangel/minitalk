/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 14:27:02 by snpark            #+#    #+#             */
/*   Updated: 2021/06/22 15:40:16 by senoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>


void	test(int sig)
{
	if (sig == SIGUSR1)
		write(1, "0", 1);
	if (sig == SIGUSR2)
		write(1, "1", 1);
}

int		main(void)
{
	pid_t		pid;
	sigset_t	sigset;
	void	(*ft)(int);
	struct sigaction	arg_sa;
	struct sigaction	tmp;

	arg_sa.sa_flags = SA_NODEFER;
	arg_sa.sa_handler = test;
//signal setting
	sigemptyset(&sigset);
	if (!sigaddset(&sigset, SIGUSR1))
		printf("ok 1\n");
	else
		printf("fail 1\n");
	if (!sigaddset(&sigset, SIGUSR2))
		printf("ok 2\n");
	else
		printf("fail 2\n");
	if (sigismember(&sigset, SIGUSR1))
		printf("in it 1\n");
	else
		printf("no 1\n");
	if (sigismember(&sigset, SIGUSR2))
		printf("in it 2\n");
	else
		printf("no 2\n");
	arg_sa.sa_mask = sigset;
	signal(SIGUSR1, test);
	signal(SIGUSR2, test);
//get pid & print pid
	pid = getpid();
	ft_putnbr(pid);
	write(1, "\n", 1);
	while (1)
		pause();
	write(1, "\n", 1);
	printf("end\n");
}
