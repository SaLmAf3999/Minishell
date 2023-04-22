/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_cmds2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakayumo <fakayumo@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 00:15:39 by fakayumo          #+#    #+#             */
/*   Updated: 2023/04/23 00:15:41 by fakayumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*----------------------------------------------*/
t_cmd2	*ft_make_cmd2(t_token *token)
{
	t_cmd2	*cmd;

	cmd = NULL;
	while (token)
	{
		if (token && token->type != PIPE)
		{
			if (!cmd)
				cmd = create_cmd2(&token);
			else
				add_back_cmd2(&cmd, &token);
		}
		if (token && token->type == PIPE)
			token = token->next;
	}
	return (cmd);
}
/*----------------------------------------------*/

/*----------------------------------------------*/
t_cmds2	*ft_make_cmds2(t_token *token)
{
	t_cmds2	*cmds;

	cmds = NULL;
	cmds = (t_cmds2 *)malloc(sizeof(t_cmds2));
	cmds->nb_cmd = nb_pipes(token) + 1;
	cmds->cmd = ft_make_cmd2(token);
	return (cmds);
}
/*----------------------------------------------*/
