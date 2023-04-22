/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakayumo <fakayumo@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 00:07:19 by fakayumo          #+#    #+#             */
/*   Updated: 2023/04/23 00:07:22 by fakayumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*crs;
	char	*dest;

	crs = (char *)src;
	dest = (char *)dst;
	if (crs < dest)
	{
		while (len--)
		{
			dest[len] = crs[len];
		}
	}
	else
		ft_memcpy(dest, crs, len);
	return (dst);
}
