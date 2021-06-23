#ifndef MINITALK_H
# define MINITALK_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>

typedef struct char_buf_s {
	char	c;
	char	i;
}		char_buf_t;

void	ft_putnbr(int n);
void	error(char *msg);
#endif
