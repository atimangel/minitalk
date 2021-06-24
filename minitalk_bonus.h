#ifndef MINITALK_H
# define MINITALK_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <wchar.h>

typedef struct buffer_s {
	char	*str;
	char	i;
	int	len;
	int	count;
	pid_t	pid;
}		buffer_t;

int	ft_watoi(wchar_t *str);
void	ft_putnbr(int n);
void	error(char *msg);
void	recieve_len(int sig);
void	recieve_pid(int sig);
#endif
