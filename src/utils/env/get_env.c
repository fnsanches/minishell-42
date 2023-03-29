/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanches <fsanches@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 20:52:44 by fsanches          #+#    #+#             */
/*   Updated: 2023/03/27 20:55:37 by fsanches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	*get_env(char *key, char **envp, int key_len)
{
	int	i;

	i = 0;
	if (key_len < 0)
		key_len = ft_strlen(key);
	while (envp[i])
	{
		if (ft_strncmp(key, envp[i], key_len) == 0 && envp[i][key_len] == '=')
			return (ft_strdup(envp[i] + key_len + 1));
		i++;
	}
	return (NULL);
}

int	get_env_index(char *key, char **envp)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(key);
	while (envp[i])
	{
		if (ft_strncmp(key, envp[i], len) == 0 && envp[i][len] == '=')
			return (i);
		i++;
	}
	return (-1);
}
