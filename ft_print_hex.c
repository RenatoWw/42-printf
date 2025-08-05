/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 15:29:33 by ranhaia-          #+#    #+#             */
/*   Updated: 2025/08/04 20:41:37 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long long num, char flag)
{
	char	*chr;
	char	str[10];
	int		remainder;
	int		i;
	int		count;

	chr = "ABCDEF";
	i = 0;
	while (num > 0)
	{
		remainder = num % 16;
		if (remainder >= 10 && remainder <= 15)
			str[i] = chr[remainder - 10];
		if (remainder >= 0 && remainder <= 9)
			str[i] = remainder + '0';
		i++;
		num /= 16;
	}
	count = i;
	str[i] = '\0';
	if (flag == 'x')
		while (i > 0)
			ft_putchar(ft_tolower(str[--i]));
	if (flag == 'X')
		while (i > 0)
			ft_putchar(ft_toupper(str[--i]));
	return (count);
}
