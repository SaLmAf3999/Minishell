/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakayumo <fakayumo@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 23:56:41 by fakayumo          #+#    #+#             */
/*   Updated: 2023/04/22 23:56:44 by fakayumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_print(t_env *head, int out_fd)
{
	ft_putstr_fd(head->name, out_fd);
	ft_putstr_fd("=", out_fd);
	ft_putstr_fd(head->value, out_fd);
	ft_putstr_fd("\n", out_fd);
}

void	ft_env(t_env *head, int flag, int out_fd)
{
	while (head)
	{
		if (flag == 0 && head->value)
			ft_print(head, out_fd);
		else if (flag == 1)
		{
			ft_putstr_fd("declare -x ", out_fd);
			if (head->value)
			{
				ft_putstr_fd(head->name, out_fd);
				ft_putstr_fd("=\"", out_fd);
				ft_putstr_fd(head->value, out_fd);
				ft_putstr_fd("\"\n", out_fd);
			}
			else
			{
				ft_putstr_fd(head->name, out_fd);
				ft_putstr_fd("\n", out_fd);
			}
		}
		head = head->next;
	}
}
