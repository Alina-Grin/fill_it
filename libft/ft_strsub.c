/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtory <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 12:58:23 by rtory             #+#    #+#             */
/*   Updated: 2019/09/13 13:27:11 by rtory            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *new;

	if (!s)
		return (0);
	new = ft_memalloc(len + 1);
	if (new == 0)
		return (0);
	new = ft_strncpy(new, (s + start), len);
	return (new);
}
