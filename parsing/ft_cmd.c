/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakayumo <fakayumo@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 00:12:47 by fakayumo          #+#    #+#             */
/*   Updated: 2023/04/23 00:12:50 by fakayumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*----------------------------------------------*/
char	**ft_tab_args(t_token **token)
{
	char	**tab;
	int		tab_size;
	int		i;

	i = 0;
	tab_size = tab_len(*token);
	tab = (char **)malloc(sizeof(char *) * (tab_size + 1));
	while ((*token) && (*token)->type != PIPE)
	{
		tab[i] = ft_make_str((*token)->data);
		(*token) = (*token)->next;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
/*----------------------------------------------*/

/*----------------------------------------------*/
t_cmd	*create_cmd(t_token **token)
{
	t_cmd	*cmd;

	cmd = NULL;
	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->prev = NULL;
	cmd->next = NULL;
	cmd->args = ft_tab_args(token);
	return (cmd);
}
/*----------------------------------------------*/

/*----------------------------------------------*/
void	add_back_cmd(t_cmd **cmd, t_token **token)
{
	t_cmd	*tmp;
	t_cmd	*new;

	tmp = *cmd;
	to_last_cmd(cmd);
	new = create_cmd(token);
	(*cmd)->next = new;
	new->prev = (*cmd);
	*cmd = tmp;
}
/*----------------------------------------------*/
