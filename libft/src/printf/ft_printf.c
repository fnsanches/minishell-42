/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanches <fsanches@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 18:37:22 by fsanches          #+#    #+#             */
/*   Updated: 2022/05/22 02:47:41 by fsanches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			len += scan_string(format[i + 1], args);
			i++;
		}
		else
			len += len_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (len);
}

int	scan_string(const char flag, va_list args)
{
	int	len;

	len = 0;
	if (flag == 'c')
		len += len_putchar(va_arg(args, int));
	if (flag == 's')
		len += len_putstr(va_arg(args, char *));
	if (flag == 'p')
		len += len_putpointer(va_arg(args, unsigned long int));
	if (flag == 'd' || flag == 'i')
		len += len_putnum(va_arg(args, int));
	if (flag == 'u')
		len += len_putunsigned(va_arg(args, unsigned int));
	if (flag == 'x')
		len += len_puthex(va_arg(args, unsigned int), 1);
	if (flag == 'X')
		len += len_puthex(va_arg(args, unsigned int), 0);
	if (flag == '%')
		len += len_putchar('%');
	return (len);
}
