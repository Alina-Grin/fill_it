/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtory <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 21:31:07 by rtory             #+#    #+#             */
/*   Updated: 2019/09/16 17:25:04 by rtory            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new;
	int		i;

	if (!s)
		return (0);
	i = 0;
	new = ft_strnew(ft_strlen(s));
	if (new == 0)
		return (0);
	while (*(s + i))
	{
		*(new + i) = f(*(s + i));
		i++;
	}
	return (new);
}
