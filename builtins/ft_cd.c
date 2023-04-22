/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakayumo <fakayumo@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 23:56:09 by fakayumo          #+#    #+#             */
/*   Updated: 2023/04/22 23:56:11 by fakayumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../minishell.h"

void	ft_tilda(char *dir, t_env **head)
{
	char	**arr;
	char	*str;

	str = NULL;
	arr = ft_split(dir, '~');
	if (!arr[0] && ft_search_list(head, "HOME"))
		chdir(ft_search_list(head, "HOME")->value);
	else if (ft_search_list(head, "HOME"))
	{
		str = ft_strjoin(ft_search_list(head, "HOME")->value, arr[0]);
		chdir(str);
	}
}

void	cd_feature(t_env **head, char *dir)
{
	if (ft_strcmp(dir, "-") == 0)
	{
		if (ft_search_list(head, "OLDPWD")
			&& ft_strcmp(ft_search_list(head, "OLDPWD")->name, "OLDPWD") == 0)
			chdir(ft_search_list(head, "OLDPWD")->value);
	}
	else if (dir[0] == '~')
	{
		ft_tilda(dir, head);
	}
}

void	ft_help_cd(t_env **head, t_env **temp1, t_env **temp2)
{
	if ((*temp2) != NULL)
	{
		if ((*temp1))
		{
			free((*temp2)->value);
			(*temp2)->value = ft_strdup((*temp1)->value);
		}
	}
	else
	{
		if ((*temp1))
			(*temp2) = ft_create_node("OLDPWD", (*temp1)->value);
		ft_add_to_list(head, (*temp2));
	}
}

void	change_dir(t_env **head, char *dir)
{
	t_env	*temp1;
	t_env	*temp2;
	char	*str;

	str = NULL;
	cd_feature(head, dir);
	if (chdir(dir) == -1)
	{
		ft_putstr_fd(" No such file or directory\n", 2);
		g_vars->exit_status = 1;
		return ;
	}
	temp1 = ft_search_list(head, "PWD");
	temp2 = ft_search_list(head, "OLDPWD");
	ft_help_cd(head, &temp1, &temp2);
	if (temp1)
	{
		free(temp1->value);
		temp1->value = getcwd(str, 100);
	}
}

void	ft_cd(t_env **head, t_comd *command)
{
	char	*dir;
	t_env	*temp;

	if (command->next == NULL)
	{
		temp = ft_search_list(head, "HOME");
		dir = temp->value;
	}
	else if (command->next->next != NULL)
		return ;
	else
		dir = command->next->data;
	change_dir(head, dir);
}
