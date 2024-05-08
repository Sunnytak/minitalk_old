/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stak <stak@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:49:22 by stak              #+#    #+#             */
/*   Updated: 2024/05/08 16:34:11 by stak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_handler(int signal)
{
	static int	bit;
	static int	i;

	if (signal == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", i);
		bit = 0;
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("Error: wrong format.\n");
		ft_printf("Try: ./server\n");
		return (0);
	}
	pid = getpid();
	ft_printf("PID [%d]\n", pid);
	ft_printf("Waiting for a message...\n");
	while (argc == 1)
	{
		signal(SIGUSR1, ft_handler);
		signal(SIGUSR2, ft_handler);
		pause ();
	}
	return (0);
}

// void	handler(int sig)
// {
// 	static int	bit;
// 	static int	i;

// 	bit = 0;
// 	i = 0;
// 	if (sig == SIGUSR1)
// 	{
// 		i |= (0x01 << bit);
// 	}
// 	bit++;
// 	if (sig == SIGUSR2)
// 	{
// 		bit++;
// 	}
// 	if (bit == 8)
// 	{
// 		ft_printf("%c", i);
// 		bit = 0;
// 		i = 0;
// 	}
// }

// int	main(int argc, char **argv)
// {
// 	int	pid;

// 	(void)argv;
// 	if (argc != 1)
// 	{
// 		ft_printf("Error: wrong format.\n");
// 		ft_printf("Try: ./server\n");
// 		return (1);
// 	}
// 	pid = getpid();
// 	ft_printf("PID:[%d]\n", pid);
// 	ft_printf("Waiting for message...\n");
// 	while (argc == 1)
// 	{
// 		signal(SIGUSR1, handler);
// 		signal(SIGUSR2, handler);
// 		pause ();
// 	}
// 	return (0);
// }
