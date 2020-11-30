/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtory <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 16:03:53 by rtory             #+#    #+#             */
/*   Updated: 2019/09/16 17:27:08 by rtory            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	const char *str1;
	const char *str2;

	if (!s1 || !s2)
		return (0);
	str1 = s1;
	str2 = s2;
	while (*str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
	}
	if (*str1 == *str2)
		return (1);
	else
		return (0);
}
