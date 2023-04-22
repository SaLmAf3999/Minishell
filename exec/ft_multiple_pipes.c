/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multiple_pipes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakayumo <fakayumo@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 00:00:55 by fakayumo          #+#    #+#             */
/*   Updated: 2023/04/23 00:00:57 by fakayumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	reset_fd(void)
{
	dup2(g_vars->fd_in, 0);
	dup2(g_vars->fd_out, 1);
}

void	ft_multiple_pipes(t_cmd2 *commands, t_env *copy_env, int nb_cmd)
{
	t_cmd2	*temp;

	temp = commands;
	if (!(nb_cmd == 1 && check_builtin_cmds(commands)))
		ft_open_pipes(&commands);
	while (commands)
	{
		if (nb_cmd == 1 && check_builtin_cmds(commands))
			ft_builtin(commands, copy_env);
		else if (nb_cmd > 1 && check_builtin_cmds(commands))
			ft_forked_builtin(commands, copy_env, nb_cmd);
		else if (commands->comd)
			ft_cmd_exec(commands, nb_cmd);
		reset_fd();
		commands = commands->next;
	}
	ft_close_pipes(temp, nb_cmd);
	while (waitpid(-1, &g_vars->exit_status, 0) > -1)
		g_vars->exit_status = WEXITSTATUS(g_vars->exit_status);
}
