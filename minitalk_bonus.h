/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 11:27:26 by snpark            #+#    #+#             */
/*   Updated: 2021/06/25 11:38:59 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <wchar.h>

typedef struct	s_buffer
{
	char	*str;
	char	i;
	int		len;
	int		count;
	pid_t	pid;
}				t_buffer;

int				ft_watoi(wchar_t *str);
void			ft_putnbr(int n);
void			error(char *msg);
void			recieve_len(int sig);
void			recieve_pid(int sig);
#endif
