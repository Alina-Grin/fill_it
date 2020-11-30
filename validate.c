/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtory <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 18:16:54 by rtory             #+#    #+#             */
/*   Updated: 2019/11/11 18:16:56 by rtory            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	count_char(char *buf)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (i < 19)
	{
		if (buf[i] && buf[i] != '\n' && buf[i] != '#' && buf[i] != '.')
			return (0);
		if (buf[i] == '\n' && (i + 1) % 5 != 0)
			return (0);
		if (buf[i] == '#')
			count++;
		i++;
	}
	if (!buf[i] || buf[i] != '\n')
		return (0);
	return (count);
}

int	count_neighbourhood(char *buf)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (i < 19)
	{
		if (buf[i] == '#')
		{
			if (i + 1 <= 18 && buf[i + 1] == '#')
				count++;
			if (i - 1 >= 0 && buf[i - 1] == '#')
				count++;
			if (i + 5 <= 18 && buf[i + 5] == '#')
				count++;
			if (i - 5 >= 0 && buf[i - 5] == '#')
				count++;
		}
		i++;
	}
	return (count);
}

int	valid(char *buf, int size)
{
	int i;

	i = 0;
	while (i <= size)
	{
		if (count_char(buf + i) != 4)
			return (0);
		if (count_neighbourhood(buf + i) != 6 &&
			count_neighbourhood(buf + i) != 8)
			return (0);
		i += 21;
	}
	return (1);
}
