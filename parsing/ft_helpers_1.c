/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakayumo <fakayumo@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 00:14:50 by fakayumo          #+#    #+#             */
/*   Updated: 2023/04/23 00:14:53 by fakayumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*-------------------------------------------*/
int	ft_type(char c)
{
	if (c == '|')
		return (PIPE);
	else if (c == '<')
		return (LESS);
	else if (c == '>')
		return (GREAT);
	else if (c == '\'')
		return (S_QUOTE);
	else if (c == '"')
		return (D_QUOTE);
	else if (c == '$')
		return (DOLLAR);
	else if (c == ' ')
		return (W_SPACE);
	else if (c == '\n')
		return (N_LINE);
	else if (c == '\\')
		return (BACKSLASH);
	else if (c == '\\')
		return (BACKSLASH);
	return (WORD);
}
/*-------------------------------------------*/
