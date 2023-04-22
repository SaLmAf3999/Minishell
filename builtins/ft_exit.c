/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakayumo <fakayumo@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 23:57:11 by fakayumo          #+#    #+#             */
/*   Updated: 2023/04/22 23:57:13 by fakayumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static	void	ft_exit_helper(t_cmd2 *cmd)
{
	int	tmp;

	if (ft_atoi(cmd->comd->next->data))
	{
		tmp = (char)(ft_atoi(cmd->comd->next->data));
		ft_free_vars();
		exit (tmp);
	}
	else
	{
		ft_putstr_fd(cmd->comd->next->data, 2);
		ft_putstr_fd(": numeric argument required\n", 2);
		ft_free_vars();
		exit (255);
	}
}

void	ft_exit(t_cmd2 *cmd, t_env *copy_env)
{
	(void)copy_env;
	close(g_vars->fd_in);
	close(g_vars->fd_out);
	if (cmd->comd->next && cmd->comd->next->next)
	{
		ft_putstr_fd(" too many arguments\n", 2);
		ft_free_vars();
		exit (1);
	}
	else if (cmd->comd->next)
		ft_exit_helper(cmd);
	else
	{
		ft_free_vars();
		exit(0);
	}
}
