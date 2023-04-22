/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakayumo <fakayumo@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 00:12:55 by fakayumo          #+#    #+#             */
/*   Updated: 2023/04/23 00:12:58 by fakayumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*-----------------------------------------*/
void	to_last_cmd2(t_cmd2 **cmd)
{
	while ((*cmd) && (*cmd)->next)
		(*cmd) = (*cmd)->next;
}
/*------------------------------------------*/

/*------------------------------------------*/
t_cmd2	*create_cmd2(t_token **token)
{
	t_cmd2	*cmd;

	cmd = NULL;
	cmd = (t_cmd2 *)malloc(sizeof(t_cmd2));
	if (!cmd)
		return (NULL);
	cmd->prev = NULL;
	cmd->next = NULL;
	cmd->comd = ft_make_comd(token);
	cmd->input = ft_make_input(token);
	cmd->output = ft_make_output(token);
	return (cmd);
}
/*-------------------------------------------*/

/*-------------------------------------------*/
void	add_back_cmd2(t_cmd2 **cmd, t_token **token)
{
	t_cmd2	*tmp;
	t_cmd2	*new;

	tmp = *cmd;
	to_last_cmd2(cmd);
	new = create_cmd2(token);
	(*cmd)->next = new;
	new->prev = (*cmd);
	*cmd = tmp;
}
/*----------------------------------------------*/
