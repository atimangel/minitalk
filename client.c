/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 14:27:20 by snpark            #+#    #+#             */
/*   Updated: 2021/06/16 13:44:24 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
	//take from server as parameter
	//pid
	//string
}
