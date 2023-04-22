/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakayumo <fakayumo@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 00:02:30 by fakayumo          #+#    #+#             */
/*   Updated: 2023/04/23 00:02:32 by fakayumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int arg)
{
	if (arg <= 'z' && arg >= 'a')
		return (1);
	else if (arg <= 'Z' && arg >= 'A')
		return (1);
	else if (arg <= '9' && arg >= '0')
		return (1);
	else
		return (0);
}
