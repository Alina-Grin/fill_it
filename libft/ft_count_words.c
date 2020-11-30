/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtory <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 18:42:20 by rtory             #+#    #+#             */
/*   Updated: 2019/09/13 20:23:45 by rtory            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_count_words(const char *s, char c)
{
	size_t	count;
	int		tmp;

	tmp = 0;
	count = 0;
	while (*s)
	{
		if (tmp == 1 && *s == c)
			tmp = 0;
		if (tmp == 0 && *s != c)
		{
			tmp = 1;
			count++;
		}
		s++;
	}
	return (count);
}
