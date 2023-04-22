/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakayumo <fakayumo@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 23:59:30 by fakayumo          #+#    #+#             */
/*   Updated: 2023/04/22 23:59:35 by fakayumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_dup2(t_cmd2 *commands, int fd_in, int fd_out)
{
	if (fd_out > 1)
	{
		if (dup2(fd_out, STDOUT_FILENO) < 0)
			ft_putstr_fd("writing  file failed\n", 2);
	}
	else if (commands->next != NULL)
	{
		if (dup2(commands->fd[1], STDOUT_FILENO) < 0)
			ft_putstr_fd("writing1 failed to pipe\n", 2);
	}
	if (fd_in > 0)
	{
		if (dup2(fd_in, STDIN_FILENO) < 0)
			ft_putstr_fd("reading  file failed\n", 2);
	}
	else if (commands->prev)
	{
		if (dup2(commands->prev->fd[0], STDIN_FILENO) < 0)
			ft_putstr_fd("writing2 failed to pipe\n", 2);
	}
}
