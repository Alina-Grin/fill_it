/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtory <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 16:15:04 by rtory             #+#    #+#             */
/*   Updated: 2019/09/17 15:45:03 by rtory            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t		i;
	const char	*str1;
	const char	*str2;

	if (!s1 || !s2)
		return (0);
	if (n == 0)
		return (1);
	i = 0;
	str1 = s1;
	str2 = s2;
	n -= 1;
	while (*str1 && (*str1 == *str2) && (n--))
	{
		str1++;
		str2++;
	}
	if (*str1 == *str2)
		return (1);
	else
		return (0);
}
