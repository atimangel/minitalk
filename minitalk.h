/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 11:31:26 by snpark            #+#    #+#             */
/*   Updated: 2021/06/25 11:34:57 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>

typedef struct	s_char_buf{
	char		c;
	char		i;
}				t_char_buf;

void			ft_putnbr(int n);
void			error(char *msg);
#endif
