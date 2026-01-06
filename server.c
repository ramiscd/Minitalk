// #include "minitalk.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>

void handle_signal(int sig)
{
    static unsigned char current_char = 0;
    static int bit_count = 0;

    current_char <<= 1;
    if(sig == SIGUSR2)
        current_char |= 1;
    
    bit_count++;

    if (bit_count == 8)
    {
        if (current_char == '\0')
            write(1, "\n", 1);
        else
            write(1, &current_char, 1);

        current_char = 0;
        bit_count = 0;
    }
}

void	ft_putnbr(int n)
{
	char	c;
	long	nb;

	nb = n;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);
	c = (nb % 10) + '0';
	write(1, &c, 1);
}

int main()
{
    pid_t pid;

    pid = getpid();

    write(1, "Server PID: ", 12);
    ft_putnbr(pid);
    write(1, "\n", 1);

    signal(SIGUSR1, handle_signal);
    signal(SIGUSR2, handle_signal);

    while(1)
        pause();

    return EXIT_SUCCESS;
}