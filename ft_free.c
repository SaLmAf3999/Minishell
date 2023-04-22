/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakayumo <fakayumo@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 00:18:43 by fakayumo          #+#    #+#             */
/*   Updated: 2023/04/23 00:18:45 by fakayumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_copy_env(t_env *copy_env)
{
	t_env	*tmp;

	tmp = NULL;
	while (copy_env)
	{
		tmp = copy_env;
		if (copy_env->name)
			free(copy_env->name);
		if (copy_env->value)
			free(copy_env->value);
		copy_env = copy_env->next;
		free(tmp);
	}
}

void	ft_free_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

/*--------------------------------------------*/
void	ft_free_vars(void)
{
	if (g_vars && g_vars->env_clone)
		ft_free_array(g_vars->env_clone);
	if (g_vars && g_vars->copy_env)
		ft_free_copy_env(g_vars->copy_env);
	if (g_vars && g_vars->cmds)
		ft_destroy_cmds2(&(g_vars->cmds));
	if (g_vars)
		free(g_vars);
}

void	ft_free_vars2(void)
{
	if (g_vars && g_vars->env_clone)
		ft_free_array(g_vars->env_clone);
	if (g_vars && g_vars->cmds)
		ft_destroy_cmds2(&(g_vars->cmds));
}

void	ft_delete_first_n(t_comd **head)
{
	t_comd	*tmp;

	tmp = *head;
	*head = tmp->next;
	free(tmp);
}
/*--------------------------------------------*/
