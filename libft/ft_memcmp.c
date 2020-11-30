/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtory <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 12:39:49 by rtory             #+#    #+#             */
/*   Updated: 2019/09/16 15:41:14 by rtory            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t					i;
	const unsigned char		*dest;
	const unsigned char		*src;

	i = 0;
	dest = s1;
	src = s2;
	while ((n > i) && (dest[i] == src[i]))
		++i;
	if (i == n)
		return (0);
	return (dest[i] - src[i]);
}
