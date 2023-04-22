/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakayumo <fakayumo@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 23:58:32 by fakayumo          #+#    #+#             */
/*   Updated: 2023/04/22 23:58:35 by fakayumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_unset(t_env **head, t_comd *command)
{
	while (command)
	{
		ft_delete_from_list(head, command->data);
		command = command->next;
	}
}
