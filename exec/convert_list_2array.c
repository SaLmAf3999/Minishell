/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_list_2array.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakayumo <fakayumo@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 23:58:57 by fakayumo          #+#    #+#             */
/*   Updated: 2023/04/22 23:59:00 by fakayumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_listsize1(t_comd *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}

int	ft_listsize2(t_env *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}

char	**ft_get_2darray1(t_comd *cmd)
{
	char	**arr;
	int		list_size;
	int		i;

	list_size = ft_listsize1(cmd);
	arr = malloc(sizeof(arr) * (list_size + 1));
	i = 0;
	while (cmd)
	{
		arr[i] = ft_strdup(cmd->data);
		i++;
		cmd = cmd->next;
	}
	arr[i] = 0;
	return (arr);
}

char	**ft_get_2darray2(t_env *env)
{
	char	**arr;
	int		list_size;
	char	*tmp1;
	char	*tmp2;
	int		i;

	list_size = ft_listsize2(env);
	arr = malloc(sizeof(char *) * (list_size + 1));
	tmp1 = NULL;
	tmp2 = NULL;
	i = 0;
	while (env)
	{
		tmp1 = ft_strjoin(env->name, "=");
		if (env->value)
		{
			tmp2 = ft_strjoin(tmp1, env->value);
			arr[i] = ft_strdup(tmp2);
			i++;
		}
		env = env->next;
	}
	arr[i] = 0;
	return (arr);
}
