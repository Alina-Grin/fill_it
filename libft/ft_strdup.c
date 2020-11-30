/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtory <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 15:57:23 by rtory             #+#    #+#             */
/*   Updated: 2019/09/04 17:58:48 by rtory            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		count;
	char	*str;

	count = 0;
	while (s[count] != '\0')
		++count;
	str = (char*)malloc(sizeof(char) * (count + 1));
	if (str == 0)
		return (0);
	count = 0;
	while (s[count] != '\0')
	{
		str[count] = s[count];
		count++;
	}
	str[count] = '\0';
	return (str);
}
