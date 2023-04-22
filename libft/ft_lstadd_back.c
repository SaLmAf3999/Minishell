/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakayumo <fakayumo@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 00:03:32 by fakayumo          #+#    #+#             */
/*   Updated: 2023/04/23 00:03:34 by fakayumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*l;

	if (!new)
		return ;
	if (!alst || !(*alst))
	{
		*alst = new;
		return ;
	}
	l = *alst;
	while (l->next)
		l = l->next;
	l->next = new;
}
