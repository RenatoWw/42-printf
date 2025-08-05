/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:40:08 by ranhaia-          #+#    #+#             */
/*   Updated: 2025/08/04 21:00:46 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// tratar a put ptr como void *ptr
// criar uma
int	ft_putptr(unsigned long long num)
{
	int	count;

	count = 0;
	count += ft_putstr("0x");
	count += ft_puthex(num, 'x');
	return (count);
}
