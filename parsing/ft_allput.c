/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_allput.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakayumo <fakayumo@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 00:12:33 by fakayumo          #+#    #+#             */
/*   Updated: 2023/04/23 00:12:35 by fakayumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*----------------------------------------------*/
void	add_back_allput(t_allput **allput, t_token **token)
{
	t_allput	*tmp;
	t_allput	*new;

	tmp = *allput;
	to_last_allput(allput);
	new = create_allput(token);
	(*allput)->next = new;
	new->prev = (*allput);
	*allput = tmp;
}
/*--------------------------------------------*/

/*----------------------------------------------*/
t_allput	*ft_make_input(t_token **token)
{
	t_allput	*input;
	t_token		*tmp;

	input = NULL;
	tmp = *token;
	while (tmp)
	{
		if (tmp && tmp->type != PIPE)
		{
			if (tmp->type == LESS || tmp->type == D_LESS)
			{
				if (!input)
					input = create_allput(&tmp);
				else
					add_back_allput(&input, &tmp);
			}
		}
		if (tmp->type == PIPE)
			break ;
		tmp = tmp->next;
	}
	return (input);
}
/*----------------------------------------------*/

/*----------------------------------------------*/
t_allput	*ft_make_output(t_token **token)
{
	t_allput	*output;
	t_token		*tmp;

	output = NULL;
	tmp = *token;
	while (tmp)
	{
		if (tmp && tmp->type != PIPE)
		{
			if (tmp->type == GREAT || tmp->type == D_GREAT)
			{
				if (!output)
					output = create_allput(&tmp);
				else
					add_back_allput(&output, &tmp);
			}
		}
		if (tmp->type == PIPE)
			break ;
		tmp = tmp->next;
	}
	(*token) = tmp;
	return (output);
}
/*----------------------------------------------*/
