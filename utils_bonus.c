/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 16:13:39 by snpark            #+#    #+#             */
/*   Updated: 2021/06/25 11:40:08 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int		ft_watoi(wchar_t *str)
{
	int nbr;

	nbr = 0;
	while (*str)
	{
		nbr *= 10;
		nbr += *str - L'0';
		if (nbr < 0)
			return (-1);
		str++;
	}
	return (nbr);
}

void	ft_putnbr(int n)
{
	char c;

	if (n > 9 || n < -9)
		ft_putnbr(n / 10);
	if (n >= -9 && n < 0)
		write(1, "-", 1);
	if (n >= 0)
		c = '0' + n % 10;
	else
		c = '0' - (n % 10);
	write(1, &c, 1);
}

void	error(char *msg)
{
	write(0, "Error\n", 6);
	ft_putstr_fd(msg, 0);
	exit(0);
}
