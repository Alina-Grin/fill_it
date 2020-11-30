/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtory <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 14:34:19 by rtory             #+#    #+#             */
/*   Updated: 2019/09/16 17:34:23 by rtory            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_strlen(int n)
{
	size_t i;

	i = 0;
	while (n /= 10)
		i++;
	return (i + 1);
}

char			*ft_itoa(int n)
{
	char	*str;
	size_t	str_len;
	long	n_cpy;

	str_len = get_strlen(n);
	n_cpy = (long)n;
	if (n < 0)
	{
		n_cpy = -n_cpy;
		str_len++;
	}
	if (!(str = ft_strnew(str_len)))
		return (NULL);
	str[--str_len] = n_cpy % 10 + '0';
	while (n_cpy /= 10)
		str[--str_len] = n_cpy % 10 + '0';
	if (n < 0)
		*(str + 0) = '-';
	return (str);
}
