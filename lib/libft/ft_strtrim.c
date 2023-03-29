/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanches <fsanches@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 20:56:25 by fsanches          #+#    #+#             */
/*   Updated: 2023/03/27 20:59:52 by fsanches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	includes(const char *set, char c)
{
	while (*set)
		if (*set++ == c)
			return (0);
	return (1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start_index;
	size_t	end_index;
	char	*result;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	start_index = 0;
	end_index = ft_strlen(s1);
	while (includes(set, s1[start_index]) == 0)
		start_index++;
	if (start_index == ft_strlen(s1))
	{
		result = ft_strdup("");
		if (!result)
			return (NULL);
		else
			return (result);
	}
	while (includes(set, s1[end_index - 1]) == 0)
		end_index--;
	result = ft_substr(s1, start_index, end_index - start_index);
	return (result);
}
