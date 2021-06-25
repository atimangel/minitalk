/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 11:27:26 by snpark            #+#    #+#             */
/*   Updated: 2021/06/25 12:21:39 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>

typedef struct	s_buffer
{
	char	*str;
	char	i;
	int		len;
	int		count;
	pid_t	pid;
}				t_buffer;

void			ft_putnbr(int n);
void			error(char *msg);
void			recieve_len(int sig);
void			recieve_pid(int sig);
#endif
