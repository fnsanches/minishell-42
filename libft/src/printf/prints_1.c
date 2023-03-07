/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanches <fsanches@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 04:05:38 by fsanches          #+#    #+#             */
/*   Updated: 2022/05/22 02:47:51 by fsanches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	len_putchar(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	len_putstr(char *s)
{
	int	len;

	len = 0;
	if (!s)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	len = ft_strlen(s);
	ft_putstr_fd(s, 1);
	return (len);
}

int	len_putnum(int num)
{
	int		len;
	char	*nb;

	len = 0;
	nb = ft_itoa(num);
	len = len_putstr(nb);
	free(nb);
	return (len);
}

int	len_puthex(unsigned int num, int islower)
{
	int		len;
	char	*hex;
	int		i;

	len = 0;
	i = 0;
	hex = (char *)malloc(17 * sizeof(char));
	if (num == 0)
	{	
		len += write(1, "0", 1);
		free(hex);
		return (len);
	}
	ft_utoa(num, hex, 16);
	while (hex[i] != '\0')
	{
		if (islower == 1 && ft_isalpha(hex[i]))
			hex[i] += 32;
		i++;
	}
	len = len_putstr(hex);
	free(hex);
	return (len);
}

int	len_putpointer(unsigned long int pointer)
{
	int		len;
	char	*ptr;

	len = 0;
	ptr = (char *)malloc(33 * sizeof(char));
	if (pointer == 0)
		len += write(1, "(nil)", 5);
	else
	{
		ft_ultoa(pointer, ptr, 16);
		len += write(1, "0x", 2);
		len += len_putstr(ptr);
	}
	free(ptr);
	return (len);
}
