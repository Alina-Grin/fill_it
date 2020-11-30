/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtory <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 14:46:38 by rtory             #+#    #+#             */
/*   Updated: 2019/09/09 15:57:14 by rtory            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	int					i;
	unsigned char		*dest;
	const unsigned char	*src;

	if (s1 == 0 && s2 == 0)
		return (0);
	i = 0;
	dest = s1;
	src = s2;
	while (n--)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
