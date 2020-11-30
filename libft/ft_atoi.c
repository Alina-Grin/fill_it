/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtory <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 15:59:37 by rtory             #+#    #+#             */
/*   Updated: 2019/09/17 15:36:39 by rtory            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *s)
{
	int					neg;
	unsigned long long	num;
	unsigned long long	long_max;

	long_max = 9223372036854775807;
	neg = 1;
	num = 0;
	while (*s && ((*s >= 9 && *s <= 13) || *s == 32))
		s++;
	if (*s == '-')
		neg = -1;
	if (*s == '-' || *s == '+')
		s++;
	while (*s >= '0' && *s <= '9')
	{
		num = (num * 10) + (*s - '0');
		s++;
	}
	if (neg == 1 && num > long_max)
		return (-1);
	else if (neg == -1 && num > long_max)
		return (0);
	return (num * neg);
}
