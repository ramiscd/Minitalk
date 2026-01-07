/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramis <ramis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 21:53:30 by ramis             #+#    #+#             */
/*   Updated: 2026/01/06 22:47:40 by ramis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <sys/types.h>

void	ft_putnbr(int n);

void	handle_signal(int sig, siginfo_t *info, void *context);

void	send_string(int pid, char *string);
void	send_char(int pid, char c);
void	send_bit(int bit, int pid);
void	handle_ack(int sig);

#endif
