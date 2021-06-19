/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 14:27:20 by snpark            #+#    #+#             */
/*   Updated: 2021/06/19 10:25:59 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

int		send(int pid, char *message)
{
	int		i;
	char	c;

	while (*message)
	{
		c = *message;
		i = 0;
		while (i < 8)
		{
			if ((c >> (7 - i)) % 2 == 1)
				write(1, "1", 1);
			else
				write(1, "0", 1);
			i++;
		}
		message++;
	}
	return (1);
}

int		main(int arg_i, char **arg_s)
{
	int	pid;

	if (arg_i == 3)
	{
		pid = ft_atoi(arg_s[1]);
		send(pid, arg_s[2]);
	}
	return (0);
}