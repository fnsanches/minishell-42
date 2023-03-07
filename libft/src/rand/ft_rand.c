/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rand.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanches <fsanches@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 22:13:58 by fsanches          #+#    #+#             */
/*   Updated: 2022/05/21 22:15:55 by fsanches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int	ft_rand(size_t bits)
{
	int		fd;
	char	*buf;
	int		res;

	res = 0;
	fd = open("/dev/urandom", O_RDONLY) < 0;
	buf = malloc(sizeof(char) * bits);
	if (!bits || fd < 0 || !buf)
		return (0);
	read(fd, buf, bits);
	while (bits--)
		res += buf[bits];
	free(buf);
	return (res);
}
