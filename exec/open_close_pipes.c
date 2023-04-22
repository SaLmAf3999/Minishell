/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_close_pipes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakayumo <fakayumo@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 00:01:22 by fakayumo          #+#    #+#             */
/*   Updated: 2023/04/23 00:01:25 by fakayumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_close_pipes(t_cmd2 *commands, int nb_cmd)
{
	while (commands && commands->prev)
		commands = commands->prev;
	while (commands && nb_cmd > 1)
	{
		close(commands->fd[0]);
		close(commands->fd[1]);
		commands = commands->next;
	}
}

void	ft_open_pipes(t_cmd2 **commands)
{
	t_cmd2	*tmp;

	tmp = *commands;
	while (tmp)
	{
		if (pipe(tmp->fd) == -1)
			(strerror(errno));
		tmp = tmp->next;
	}
}
