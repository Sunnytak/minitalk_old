/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stak <stak@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:55:27 by stak              #+#    #+#             */
/*   Updated: 2024/05/08 16:36:19 by stak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bits(int pid, char i)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((i & (0x01 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][i] != '\0')
		{
			send_bits(pid, argv[2][i]);
			i++;
		}
		send_bits(pid, '\n');
	}
	else
	{
		ft_printf("Error: wrong format.\n");
		ft_printf("Try: ./client <PID> <MESSAGE>\n");
		return (1);
	}
	return (0);
}

// void	send_bit(int pid, char c)
// {
// 	int		i;
// 	char	temp_char;

// 	i = 8;
// 	temp_char = c;
// 	while (i > 0)
// 	{
// 		i--;
// 		temp_char = c >> i;
// 		if (temp_char & 1)
// 			kill(pid, SIGUSR1);
// 		else
// 			kill(pid, SIGUSR2);
// 		usleep(50);
// 	}
// }

// int	main(int argc, char **argv)
// {
// 	int		pid;
// 	char	*str;
// 	int		i;

// 	if (argc == 3)
// 	{
// 		pid = ft_atoi(argv[1]);
// 		str = argv[2];
// 		i = 0;
// 		while (str[i])
// 		{
// 			send_bit(pid, str[i++]);
// 		}
// 		send_bit(pid, '\0');
// 	}
// 	else
// 	{
// 		ft_printf("Error: wrong .\n");
// 		ft_printf("Try: ./client <pid> <message>");
// 		return (1);
// 	}
// 	return (0);
// }
