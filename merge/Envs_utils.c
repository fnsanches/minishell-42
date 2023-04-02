/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Envs_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 23:42:32 by felcaue-          #+#    #+#             */
/*   Updated: 2023/03/29 00:07:17 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "caue.h"

char	*int_to_str(int number)
{
	int		length;
	char	*string;

	length = 0;
	string = NULL;
	if (number == 0)
		return (ft_strdup("0"));
	else
	{
		length = int_len(number);
		string = (char *)malloc(sizeof(length + 1));
		string[length] = '\0';
		length--;
		while (number / 10 != 0)
		{
			string[length] = (number % 10) + '0';
			number = number / 10;
			length--;
		}
		string[length] = (number % 10) + '0';
		return (string);
	}
}

static int	int_len(unsigned int number)
{
	int	counter;

	counter = 1;
	while (number / 10 != 0)
	{
		number = number / 10;
		counter++;
	}
	return (counter);
}
