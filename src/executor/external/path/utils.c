/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanches <fsanches@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 20:54:16 by fsanches          #+#    #+#             */
/*   Updated: 2023/03/27 20:55:35 by fsanches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/minishell.h"

char	*find_command_path(char *cmd, t_data *data)
{
	char	*temp;
	char	*result;
	char	**env_splited;
	int		i;

	temp = get_env("PATH", data->envp, 4);
	env_splited = ft_split(temp, ':');
	free(temp);
	i = -1;
	result = NULL;
	while (env_splited && env_splited[++i])
	{
		free(result);
		temp = ft_strjoin(env_splited[i], "/");
		result = ft_strjoin(temp, cmd);
		free(temp);
		if (access(result, F_OK) == 0)
		{
			free_matrix(env_splited);
			return (result);
		}
	}
	free(result);
	free_matrix(env_splited);
	return (NULL);
}

char	*set_absolute_path(t_cmd *cmd)
{
	char	*result;
	char	**s;

	s = ft_split(*cmd->full_cmd, '/');
	result = ft_strdup(*cmd->full_cmd);
	free(cmd->full_cmd[0]);
	cmd->full_cmd[0] = ft_strdup(s[matrix_len(s) - 1]);
	free_matrix(s);
	return (result);
}

int	is_current_folder_dir(t_cmd *cmd)
{
	DIR	*dir;

	dir = NULL;
	if (!cmd || !cmd->full_cmd)
		return (0);
	dir = opendir(cmd->full_cmd[0]);
	if (!dir)
		return (0);
	closedir(dir);
	return (1);
}

int	send_absolute_path_to_command(t_cmd *cmd)
{
	return (cmd && cmd->full_cmd && ft_strchr(*cmd->full_cmd, '/'));
}

int	send_relative_path_to_command(t_cmd *cmd)
{
	return (!is_builtin(cmd) && cmd && cmd->full_cmd);
}
