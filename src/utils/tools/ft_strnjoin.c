/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanches <fsanches@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 21:02:58 by fsanches          #+#    #+#             */
/*   Updated: 2023/03/27 21:03:58 by fsanches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static void	join_args(int argn, va_list argl, char **result);

char	*ft_strnjoin(int argn, ...)
{
	char	*result;
	va_list	argl;

	if (argn == 0)
		return (NULL);
	va_start(argl, argn);
	result = NULL;
	join_args(argn, argl, &result);
	va_end(argl);
	return (result);
}

static void	join_args(int argn, va_list argl, char **result)
{
	char	*buf;
	char	*tmp;
	int		i;

	i = -1;
	while (++i < argn)
	{
		buf = va_arg(argl, char *);
		if (i == 0)
			*result = ft_strdup(buf);
		else
		{
			tmp = ft_strjoin(*result, buf);
			if (*result)
				free(*result);
			*result = tmp;
		}
	}
}
