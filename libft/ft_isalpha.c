/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakayumo <fakayumo@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 00:02:39 by fakayumo          #+#    #+#             */
/*   Updated: 2023/04/23 00:02:41 by fakayumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int character)
{
	if (character <= 'Z' && character >= 'A')
	{
		return (1);
	}
	else if (character <= 'z' && character >= 'a')
	{
		return (1);
	}
	else
		return (0);
}
