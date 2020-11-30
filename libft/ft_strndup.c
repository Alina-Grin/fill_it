/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtory <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 14:03:46 by rtory             #+#    #+#             */
/*   Updated: 2019/09/18 14:06:19 by rtory            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char *tmp;

	if (!(tmp = ft_strnew(n)))
		return (NULL);
	ft_strncpy(tmp, s1, n);
	return (tmp);
}
