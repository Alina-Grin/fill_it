/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtory <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 19:17:07 by rtory             #+#    #+#             */
/*   Updated: 2019/09/18 16:04:23 by rtory            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *str;

	if ((size + 1) < size)
		return (0);
	str = ft_memalloc(size + 1);
	if (str == 0)
		return (0);
	while (*str)
	{
		ft_bzero(str, (size + 1));
		++str;
	}
	return (str);
}
