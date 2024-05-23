/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stak <stak@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:52:41 by stak              #+#    #+#             */
/*   Updated: 2023/12/15 16:14:36 by stak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printstr(char *s, int *cmp)
{
	int	count;

	count = 0;
	if (!s)
	{
		return (ft_printstr("(null)", cmp));
	}
	while (*s != '\0')
	{
		ft_printchar(*s, cmp);
		s++;
		count++;
	}
	return (count);
}
