/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtory <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 20:08:38 by rtory             #+#    #+#             */
/*   Updated: 2019/09/16 17:07:58 by rtory            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_free(char **word, size_t i)
{
	while (i--)
		free(word[i]);
	free(word);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	x;
	size_t	y;
	size_t	z;
	char	**res;

	x = 0;
	z = 0;
	if (!s || !(res = (char**)malloc(sizeof(char*)
					* (ft_count_words(s, c) + 1))))
		return (NULL);
	while (x < ft_count_words(s, c))
	{
		while (s[z] == c)
			z++;
		y = ft_len_word(&s[z], c);
		if (!(res[x] = ft_strsub(&s[z], 0, y)))
		{
			ft_free(res, x);
			return (NULL);
		}
		z = z + y;
		x++;
	}
	res[x] = NULL;
	return (res);
}
