/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakayumo <fakayumo@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 00:00:45 by fakayumo          #+#    #+#             */
/*   Updated: 2023/04/23 00:00:47 by fakayumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_heredoc(char *stop_str, t_allput *input)
{
	int		pid;
	char	*get_input;

	get_input = NULL;
	g_vars->flag = 1;
	input->infile = open("heredoc.txt", O_WRONLY | O_APPEND | O_CREAT, 0644);
	pid = fork();
	if (pid < 0)
		strerror(errno);
	if (pid == 0)
	{
		while (1)
		{
			get_input = readline("here doc>");
			if (ft_strcmp(get_input, stop_str) == 0)
				exit(11);
			write(input->infile, get_input, ft_strlen(get_input));
			write(input->infile, "\n", 1);
		}
	}
	else
		g_vars->flag = 0;
	while (waitpid(-1, &g_vars->exit_status, 0) > -1)
		g_vars->exit_status = WEXITSTATUS(g_vars->exit_status);
	close(input->infile);
}

int	call_heredoc(int in_fd, t_allput *input)
{
	if (input->data->next)
		ft_heredoc(input->data->next->data, input);
	input->infile = open("heredoc.txt", O_RDONLY | O_CREAT, 0644);
	in_fd = input->infile;
	return (in_fd);
}
