/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakayumo <fakayumo@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 00:16:29 by fakayumo          #+#    #+#             */
/*   Updated: 2023/04/23 00:16:32 by fakayumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*----------------------------------------------*/
int	is_redir(int type)
{
	if (type == GREAT || type == D_GREAT || type == LESS
		|| type == D_LESS)
		return (type);
	return (0);
}
/*----------------------------------------------*/

/*----------------------------------------------*/
int	valid_redir(t_token *token)
{
	t_token	*tmp;

	tmp = token;
	while (tmp)
	{
		if (tmp && (tmp->type == GREAT || tmp->type == D_GREAT
				|| tmp->type == LESS || tmp->type == D_LESS))
		{
			tmp = tmp->next;
			while (tmp && tmp->type == W_SPACE)
				tmp = tmp->next;
			if ((tmp && tmp->type != WORD) || !tmp)
				return (1);
		}
		if (tmp)
			tmp = tmp->next;
	}
	return (0);
}
/*----------------------------------------------*/
