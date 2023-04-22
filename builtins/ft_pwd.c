/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakayumo <fakayumo@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 23:58:22 by fakayumo          #+#    #+#             */
/*   Updated: 2023/04/22 23:58:25 by fakayumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_pwd(int out_fd)
{
	char	cwd[200];

	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		write(out_fd, cwd, ft_strlen(cwd));
		write(out_fd, "\n", 1);
	}
	else
		write(out_fd, "getcwd() error\n", ft_strlen("getcwd() error\n"));
}
