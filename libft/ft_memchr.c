/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtory <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 18:43:34 by rtory             #+#    #+#             */
/*   Updated: 2019/09/16 15:38:22 by rtory            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char *dest;

	dest = (char*)s;
	c = (char)c;
	while (0 < n)
	{
		if (*dest == c)
			return (dest);
		dest++;
		n--;
	}
	return (NULL);
}
