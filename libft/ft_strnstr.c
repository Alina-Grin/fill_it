/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtory <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 20:07:04 by rtory             #+#    #+#             */
/*   Updated: 2019/09/16 15:51:37 by rtory            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t j;

	if (*s1 == 0 && *s2 == 0)
		return ((char*)(s1));
	if (*s2 == 0)
		return ((char*)(s1));
	i = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] == s2[0])
		{
			j = 1;
			while (s2[j] != '\0' && s1[i + j] == s2[j])
				++j;
			if (s2[j] == '\0' && (i + j) <= n)
				return (char*)(s1 + i);
		}
		++i;
	}
	return (NULL);
}
