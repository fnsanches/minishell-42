/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanches <fsanches@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 20:49:51 by fsanches          #+#    #+#             */
/*   Updated: 2023/03/27 21:06:40 by fsanches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int g_status;

pid_t get_pid(t_data *result)
{
	pid_t pid;

	pid = fork();
	if (pid < 0)
	{
		throw_error(FORKERR, 1, NULL);
		exit(1);
	}
	if (pid == 0)
	{
		free_data(result);
		exit(1);
	}
	waitpid(pid, NULL, 0);
	return (pid - 1);
}

void init_vars(t_data *data, char *program_name)
{
	init_pwd(data);
	init_shlvl(data);
	init_path(data);
	init_executable(data, program_name);
}

t_data init_data(char **argv, char **envp)
{
	t_data result;

	result.input = NULL;
	result.cmds = NULL;
	result.running = 1;
	result.envp = dup_matrix(envp);
	result.pid = get_pid(&result);
	g_status = 0;
	init_vars(&result, argv[0]);
	return (result);
}

void input_loop(t_data *data)
{
	char *prompt;

	clear_window();
	while (data->running)
	{
		set_default_signal_handlers();
		prompt = get_prompt(data);
		data->input = readline(prompt);
		if (!handle_input(data))
			data->running = 0;
	}
}

int minishell(char **argv, char **envp)
{
	t_data data;

	data = init_data(argv, envp);
	input_loop(&data);
	free_data(&data);
	return (g_status);
}
