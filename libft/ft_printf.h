/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stak <stak@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:00:31 by stak              #+#    #+#             */
/*   Updated: 2023/12/18 12:17:08 by stak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_printnbr(int n, int *cmp);
int	ft_printstr(char *s, int *cmp);
int	ft_printchar(int c, int *cmp);
int	ft_hexconvert(unsigned long long int n, const char check, int *cmp);
int	ft_print_unsigned(unsigned int n, int *cmp);
int	ft_print_ptr(void *s, int *cmp);

#endif
