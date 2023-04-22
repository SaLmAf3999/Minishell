/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroyers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakayumo <fakayumo@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 00:14:41 by fakayumo          #+#    #+#             */
/*   Updated: 2023/04/23 00:14:43 by fakayumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*----------------------------------------------*/
void	ft_destroy_tokens(t_token **token)
{
	t_token	*tmp;

	while (*token)
	{
		tmp = (*token)->next;
		if (*token && (*token)->data)
		{
			free((*token)->data);
			(*token)->data = NULL;
		}
		free(*token);
		(*token) = tmp;
	}
}
/*---------------------------------------------*/

/*----------------------------------------------*/
void	ft_destroy_comd(t_comd **comd)
{
	t_comd	*tmp;

	while (*comd)
	{
		tmp = (*comd)->next;
		if (*comd)
		{
			free((*comd)->data);
			(*comd)->data = NULL;
		}
		free(*comd);
		(*comd) = tmp;
	}
}
/*----------------------------------------------*/

/*----------------------------------------------*/
void	ft_destroy_allput(t_allput **allput)
{
	t_allput	*tmp;

	while (*allput)
	{
		tmp = (*allput)->next;
		if (*allput)
		{
			ft_destroy_comd(&(*allput)->data);
			(*allput)->data = NULL;
		}
		free(*allput);
		(*allput) = tmp;
	}
}
/*----------------------------------------------*/

/*----------------------------------------------*/
void	ft_destroy_cmd2(t_cmd2 **cmd)
{
	t_cmd2	*tmp;

	tmp = NULL;
	while (*cmd)
	{
		tmp = (*cmd)->next;
		ft_destroy_comd(&(*cmd)->comd);
		ft_destroy_allput(&(*cmd)->input);
		ft_destroy_allput(&(*cmd)->output);
		free(*cmd);
		(*cmd) = tmp;
	}
}
/*----------------------------------------------*/

/*----------------------------------------------*/
void	ft_destroy_cmds2(t_cmds2 **cmds)
{
	ft_destroy_cmd2(&(*cmds)->cmd);
	free(*cmds);
}
/*----------------------------------------------*/
