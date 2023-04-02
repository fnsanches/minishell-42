/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Env_splitter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 23:23:05 by felcaue-          #+#    #+#             */
/*   Updated: 2023/03/29 00:05:42 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "caue.h"

char	**splitter(char *str)
{
	int		counter;
	char	**str_l;

	counter = 0;
	str_l = (char **)malloc(sizeof(char **) * 2);
	str_l[0] = (char *)malloc(sizeof(char) * (characters_c(str, '=') + 1));
	str_l[1] = (char *)malloc(sizeof(char)
			* ((ft_strlen(str) - characters_c(str, '=')) + 1));
	while (str[counter] != '=' && str[counter])
	{
		str_l[0][counter] = str[counter];
		counter++;
	}
	str_l[0][counter] = '\0';
	aftr_equal(str, str_l, counter);
	return (str_l);
}

void	aftr_equal(char *string, char **str, int id)
{
	int	auxs;

	auxs = 0;
	if (string[id] == '=' && string[id + 1] == '\0')
		str[1][0] = '\0';
	else if (string[id] == '\0')
	{
		free(str[1]);
		str[1] = NULL;
	}
	else
	{
		while (string[++id] != '\0')
			str[1][auxs++] = string[auxs];
		str[1][auxs] = '\0';
	}
}

static int	characters_c(char *string, char chr)
{
	int		counter;

	counter = 0;
	while (string[counter] && string[counter] != chr)
	{
		counter++;
	}
	return (counter);
}
