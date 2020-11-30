/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtory <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 17:25:47 by rtory             #+#    #+#             */
/*   Updated: 2019/09/16 15:35:02 by rtory            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	size_t				i;
	unsigned char		*dest;
	const unsigned char	*src;

	if (s1 == 0 && s2 == 0)
		return (0);
	i = 0;
	dest = s1;
	src = s2;
	c = (unsigned char)c;
	while (i < n)
	{
		dest[i] = src[i];
		if (src[i] == c)
			return (dest + i + 1);
		i++;
	}
	return (NULL);
}
