/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtory <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 13:57:25 by rtory             #+#    #+#             */
/*   Updated: 2019/09/18 17:17:12 by rtory            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*new;
	int		i;
	int		k;
	size_t	j;

	if (!s)
		return (0);
	i = 0;
	k = 0;
	j = ft_strlen(s + 1);
	while (*(s + i) == ' ' || *(s + i) == '\n' || *(s + i) == '\t')
		i++;
	if (*(s + i) == '\0')
	{
		new = ft_strnew('\0');
		return (new);
	}
	while (*(s + j) == ' ' || *(s + j) == '\n' || *(s + j) == '\t')
		j--;
	new = ft_strnew(j - i + 1);
	if (new == 0)
		return (0);
	while (i <= (int)j)
		*(new + k++) = *(s + i++);
	return (new);
}
