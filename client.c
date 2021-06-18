/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 14:27:20 by snpark            #+#    #+#             */
/*   Updated: 2021/06/18 16:54:11 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		send(int pid, char *message)
{
	int i;

	i = 0;
	while (message)
	{
		kill(pid);
		*message >>= 1;
		i++;
		if (i == 8)
		{
			i = 0;
			message++;
		}
	}
}

int		main(int arg_i, char **arg_s)
{
	int	pid;

	if (arg_i == 3)
	{
		pid = ft_atoi(arg_s[1]);
		ft_putnbr(pid);
		write(1, arg_s[2], ft_strlen(arg_s[2]));
	}
	return (0);
}
