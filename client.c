/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stak <stak@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:55:27 by stak              #+#    #+#             */
/*   Updated: 2024/05/06 14:13:12 by stak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	send_bit(int pid, char c)
{
	int		i;
	char	temp_char;

	i = 8;
	temp_char = c;
	while (i > 0)
	{
		i--;
		temp_char = c >> i;
		if (temp_char % 2 == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(10);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*str;
	int		i;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		str = argv[2];
		i = 0;
		while (str[i])
			send_bit(pid, str[i++]);
		send_bit (pid, '\0');
	}
	else
		ft_printf("ajdjdas");
	return (0);
}
