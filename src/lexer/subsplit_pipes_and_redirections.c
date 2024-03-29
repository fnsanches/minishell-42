/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subsplit_pipes_and_redirections.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanches <fsanches@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 20:53:26 by fsanches          #+#    #+#             */
/*   Updated: 2023/03/27 20:55:36 by fsanches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	ft_count_words(const char *s, char *set, int count)
{
	int	q[2];
	int	i;

	i = 0;
	q[0] = 0;
	q[1] = 0;
	while (s && s[i] != '\0')
	{
		count++;
		if (!ft_strchr(set, s[i]))
		{
			while ((!ft_strchr(set, s[i]) || q[0] || q[1]) && s[i] != '\0')
			{
				q[0] = (q[0] + (!q[1] && s[i] == '\'')) % 2;
				q[1] = (q[1] + (!q[0] && s[i] == '\"')) % 2;
				i++;
			}
			if (q[0] || q[1])
				return (-1);
		}
		else
			i++;
	}
	return (count);
}

static char	**ft_fill_array(char **aux, const char *s, char *set, int i[3])
{
	int	q[2];

	q[0] = 0;
	q[1] = 0;
	while (s && s[i[0]] != '\0')
	{
		i[1] = i[0];
		if (!ft_strchr(set, s[i[0]]))
		{
			while ((!ft_strchr(set, s[i[0]]) || q[0] || q[1]) && s[i[0]])
			{
				q[0] = (q[0] + (!q[1] && s[i[0]] == '\'')) % 2;
				q[1] = (q[1] + (!q[0] && s[i[0]] == '\"')) % 2;
				i[0]++;
			}
		}
		else
			i[0]++;
		aux[i[2]++] = ft_substr(s, i[1], i[0] - i[1]);
	}
	return (aux);
}

static char	**split_pipes_and_redirections(char const *s, char *set)
{
	char	**result;
	int		nwords;
	int		i[3];

	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	if (!s)
		return (NULL);
	nwords = ft_count_words(s, set, 0);
	if (nwords == -1)
		return (NULL);
	result = malloc((nwords + 1) * sizeof(char *));
	if (result == NULL)
		return (NULL);
	result = ft_fill_array(result, s, set, i);
	result[nwords] = NULL;
	return (result);
}

char	**subsplit_pipes_and_redirections(char **args)
{
	char	**result;
	char	**subsplit;
	int		i;
	int		j;

	result = NULL;
	i = 0;
	while (args && args[i])
	{
		subsplit = split_pipes_and_redirections(args[i], "<|>");
		j = 0;
		while (subsplit[j])
			result = matrix_push(result, subsplit[j++]);
		free_matrix(subsplit);
		i++;
	}
	free_matrix(args);
	return (result);
}
