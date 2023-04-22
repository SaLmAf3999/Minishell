/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_close.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakayumo <fakayumo@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 00:01:32 by fakayumo          #+#    #+#             */
/*   Updated: 2023/04/23 00:01:34 by fakayumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_open_infile(t_allput *input)
{
	int	in_fd;

	in_fd = 0;
	if (input && input->infile > 0)
		close(input->infile);
	while (input)
	{
		if (ft_strcmp(input->data->data, "<") == 0)
		{
			input->infile = open(input->data->next->data, O_RDONLY);
			in_fd = input->infile;
			if (in_fd < 0)
			{
				ft_putstr_err(input->data->next->data, strerror(errno));
				break ;
			}
		}
		else if (ft_strcmp(input->data->data, "<<") == 0)
			in_fd = call_heredoc(in_fd, input);
		if (input->infile == -1)
			ft_putstr_err(input->data->next->data, strerror(errno));
		input = input->next;
	}
	return (in_fd);
}

int	ft_open_outfile_helper(t_allput *output)
{
	int	out_fd;

	out_fd = 1;
	if (ft_strcmp(output->data->data, ">") == 0)
	{
		output->outfile = open(output->data->next->data,
				O_RDWR | O_CREAT | O_TRUNC, 0644);
		out_fd = output->outfile;
	}
	else if (ft_strcmp(output->data->data, ">>") == 0)
	{
		output->outfile = open(output->data->next->data,
				O_RDWR | O_CREAT | O_APPEND, 0644);
		out_fd = output->outfile;
	}
	return (out_fd);
}

int	ft_open_outfile(t_allput *output)
{
	int	out_fd;

	out_fd = 1;
	while (output)
	{
		out_fd = ft_open_outfile_helper(output);
		if (output->outfile == -1)
		{
			ft_putstr_err(output->data->next->data, strerror(errno));
			break ;
		}
		output = output->next;
	}
	return (out_fd);
}

void	ft_close_outfile(t_allput *output)
{
	while (output)
	{
		close(output->outfile);
		output = output->next;
	}
}

void	ft_close_infile(t_allput *input)
{
	while (input)
	{
		close(input->infile);
		input = input->next;
	}
}
