/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakayumo <fakayumo@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 23:59:46 by fakayumo          #+#    #+#             */
/*   Updated: 2023/04/22 23:59:49 by fakayumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_math_instructions(t_cmd2 *cmds, char oper)
{
	int	result;

	result = 0;
	if (cmds->comd->next->next->next)
	{
		if (oper == '+')
			result = ft_atoi(cmds->comd->next->data)
				+ ft_atoi(cmds->comd->next->next->next->data);
		else if (oper == '-')
			result = ft_atoi(cmds->comd->next->data)
				- ft_atoi(cmds->comd->next->next->next->data);
		else if (oper == '*')
			result = ft_atoi(cmds->comd->next->data)
				* ft_atoi(cmds->comd->next->next->next->data);
		else if (oper == '/')
			result = ft_atoi(cmds->comd->next->data)
				/ ft_atoi(cmds->comd->next->next->next->data);
		cmds->comd->next->data = ft_strdup(ft_itoa(result));
		ft_delete_first_n(&cmds->comd->next->next);
		ft_delete_first_n(&cmds->comd->next->next);
	}
}

void	ft_math_helper(t_cmd2 *cmds)
{
	if (cmds->comd->next->next->data[0] == '+')
		ft_math_instructions(cmds, '+');
	else if (cmds->comd->next->next->data[0] == '-')
		ft_math_instructions(cmds, '-');
	else if (cmds->comd->next->next->data[0] == '*')
		ft_math_instructions(cmds, '*');
	else if (cmds->comd->next->next->data[0] == '/')
		ft_math_instructions(cmds, '/');
}

void	ft_expr(t_cmd2 *cmds)
{
	char	*tmp;

	tmp = NULL;
	if (ft_strcmp(cmds->comd->data, "expr") == 0)
	{
		if (cmds->comd->next)
		{
			if (ft_strcmp(cmds->comd->next->data, "$?") == 0)
			{
				tmp = ft_itoa(g_vars->exit_status);
				cmds->comd->next->data = ft_strdup(tmp);
			}
			if (cmds->comd->next->next->next
				&& ft_strcmp(cmds->comd->next->next->next->data, "$?") == 0)
			{
				tmp = ft_itoa(g_vars->exit_status);
				cmds->comd->next->next->next->data = ft_strdup(tmp);
			}
		}
		if (cmds->comd->next->next)
			ft_math_helper(cmds);
	}
}
