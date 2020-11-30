/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtory <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 13:47:44 by rtory             #+#    #+#             */
/*   Updated: 2019/09/16 15:36:53 by rtory            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	char		*dest;
	const char	*src;

	if (s1 == 0 && s2 == 0)
		return (0);
	dest = s1;
	src = s2;
	if (src > dest)
		return (ft_memcpy(dest, src, n));
	else
		while (n--)
		{
			dest[n] = src[n];
		}
	return (s1);
}
