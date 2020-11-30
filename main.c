/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtory <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 18:15:52 by rtory             #+#    #+#             */
/*   Updated: 2019/11/12 13:58:54 by rtory            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	t_piece *piecelist;

	if (ac != 2)
	{
		ft_putstr("usage: ./fillit source_file\n");
		return (1);
	}
	if ((piecelist = parser(av[1])) == NULL)
	{
		ft_putstr("error\n");
		return (1);
	}
	solve(piecelist);
	free_piecelist(piecelist);
	return (1);
}
