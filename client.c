/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramis <ramis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 21:53:08 by ramis             #+#    #+#             */
/*   Updated: 2026/01/06 23:29:30 by ramis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_ack = 0;

void	handle_ack(int sig)
{
	(void)sig;
	g_ack = 1;
}

void	send_bit(int bit, int pid)
{
	g_ack = 0;
	if (bit == 0)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	while (!g_ack)
		pause();
}

void	send_char(int pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		send_bit((c >> i) & 1, pid);
		i--;
	}
}

void	send_string(int pid, char *string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		send_char(pid, string[i]);
		i++;
	}
	send_char(pid, '\0');
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		write(1, "Uso: ./client <PID> <mensagem>\n", 32);
		return (1);
	}
	signal(SIGUSR1, handle_ack);
	pid = atoi(argv[1]);
	send_string(pid, argv[2]);
	return (0);
}
