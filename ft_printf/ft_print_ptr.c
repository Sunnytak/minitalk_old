/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stak <stak@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:08:22 by stak              #+#    #+#             */
/*   Updated: 2023/12/15 16:20:32 by stak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(void *s, int *cmp)
{
	unsigned long long int	i;
	int						count;
	char					check;

	count = 0;
	check = 'x';
	i = (unsigned long long int) s;
	count += ft_printstr("0x", cmp);
	count += ft_hexconvert(i, check, cmp);
	return (count);
}
