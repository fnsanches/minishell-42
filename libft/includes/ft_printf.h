/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanches <fsanches@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 18:35:45 by fsanches          #+#    #+#             */
/*   Updated: 2022/06/26 00:41:00 by fsanches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

int		ft_printf(const char *received_str, ...);
int		scan_string(const char flag, va_list args);

// print utils
int		len_putnum(int num);
int		len_puthex(unsigned int num, int islower);
int		len_putpointer(unsigned long int pointer);
int		len_putchar(int c);
int		len_putstr(char *s);
int		len_putunsigned(unsigned int num);

#endif