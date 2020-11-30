/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtory <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 21:46:21 by rtory             #+#    #+#             */
/*   Updated: 2019/09/16 17:26:23 by rtory            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
		*(new + i) = f(i, (*(s + i)));
		i++;
	}
	return (new);
}
