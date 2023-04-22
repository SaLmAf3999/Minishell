/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakayumo <fakayumo@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 00:14:23 by fakayumo          #+#    #+#             */
/*   Updated: 2023/04/23 00:14:25 by fakayumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*-----------------------------------------------------*/
char	*ft_dollar_helper(t_token **token)
{
	char	*new_str;

	new_str = NULL;
	if ((*token) && (*token)->next && is_another_symb((*token)->next->data))
	{
		if ((*token)->next->type == D_QUOTE)
			new_str = ft_strdup((*token)->data);
		else
		{
			if ((*token) && (*token)->next
				&& ft_isalpha((*token)->next->data[0]))
				new_str = ft_trans_str((*token)->next->data);
			else
				new_str = ft_strjoin((*token)->data, (*token)->next->data);
		}
	}
	else if ((*token) && (*token)->next
		&& is_another_digit((*token)->next->data))
		new_str = ft_substr((*token)->next->data,
				1, ft_strlen((*token)->next->data) - 1);
	else if ((*token) && (*token)->next)
		new_str = ft_find_var((*token)->next->data);
	else
		new_str = ft_strdup((*token)->data);
	return (new_str);
}
/*-----------------------------------------------------*/

/*-----------------------------------------------------*/
int	ft_dummpy_token_check(t_token *token, char **str)
{
	int		i;
	t_token	*dummy_token;

	i = 0;
	dummy_token = token;
	while (dummy_token && dummy_token->prev)
		dummy_token = dummy_token->prev;
	while (dummy_token)
	{
		if ((dummy_token->data) == *str)
			i = 1;
		dummy_token = dummy_token->next;
	}
	return (i);
}
/*-----------------------------------------------------*/
