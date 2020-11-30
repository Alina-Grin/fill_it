/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtory <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 14:55:48 by rtory             #+#    #+#             */
/*   Updated: 2019/09/17 15:09:42 by rtory            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *s1, const char *s2, size_t size)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*pointer_to_s1;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (size <= s1_len)
		return (s2_len + size);
	else if (s1_len + 1 < size)
	{
		pointer_to_s1 = ft_strchr(s1, '\0');
		ft_memccpy(pointer_to_s1, s2, '\0', size - s1_len - 1);
		if (size <= s1_len + s2_len)
			s1[size - 1] = '\0';
	}
	return (s1_len + s2_len);
}
