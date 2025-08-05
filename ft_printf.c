/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 04:28:10 by ranhaia-          #+#    #+#             */
/*   Updated: 2025/08/04 21:26:46 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* %c
 * %s
 * %p
 * %d
 * %i
 * %u
 * %x
 * %X
 * %%
*/

// static char	check_conversion(char c)
// {
// 	if (c == 'c')
// 		printf("caractere");
// }

// arrumar puthex
// tratar a put ptr como void *ptr

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != '%')
		{
			count += ft_putchar(str[i]);
		}
		else
		{
			if (str[i] == '%' && str[i + 1] == 'c')
			{
				count += ft_putchar(va_arg(args, int));
				i++;
			}
			if (str[i] == '%' && str[i + 1] == 's')
			{
				count += ft_putstr(va_arg(args, char *));
				i++;
			}
			if (str[i] == '%' && str[i + 1] == 'p')
			{
				count += ft_putptr(va_arg(args, unsigned long long));
				i++;
			}
			if (str[i] == '%' && (str[i + 1] == 'd' || str[i + 1] == 'i'))
			{
				count += ft_putnbr(va_arg(args, int));
				i++;
			}
			if (str[i] == '%' && str[i + 1] == 'u')
			{
				count += ft_putunbr(va_arg(args, unsigned int));
				i++;
			}
			if (str[i] == '%' && str[i + 1] == 'x')
			{
				count += ft_puthex(va_arg(args, unsigned long long), 'x');
				i++;
			}
			if (str[i] == '%' && str[i + 1] == 'X')
			{
				count += ft_puthex(va_arg(args, unsigned long long), 'X');
				i++;
			}
			if (str[i] == '%' && str[i + 1] == '%')
			{
				count += ft_putchar('%');
				i++;
			}
		}
		
		i++;
	}
	va_end(args);
	return (count);
}

// int	main(void)
// {
// 	unsigned int	num;
// 	void			*p;

// 	p = &num;
// 	num = 4244334;
// 	// printf("\nlen: %d\n", printf("%cello my name is renato", 'h'));
// 	// ft_printf("\nlen: %d\n", ft_printf("%cello my name is renato", 'h'));
// 	ft_printf(" NULL %s NULL ", NULL);
// 	return (0);
// }
