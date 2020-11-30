/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szeftyr <szeftyr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 18:17:22 by rtory             #+#    #+#             */
/*   Updated: 2019/11/24 15:47:00 by szeftyr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		round_up_sqr(int num)
{
	int	map_size;

	map_size = 2;
	while (map_size * map_size < num)
		map_size++;
	return (map_size);
}

t_map	*new_map(int map_size)
{
	t_map	*map;
	int		i;

	if (!(map = (t_map *)ft_memalloc(sizeof(t_map))))
		return (NULL);
	if (!(map->array = (char**)ft_memalloc(sizeof(char*) * map_size)))
		return (NULL);
	i = 0;
	while (i < map_size)
	{
		if (!(map->array[i] = ft_strnew(map_size)))
		{
			while (i > 0)
			{
				ft_strdel(&map->array[i]);
				i--;
			}
			free(map->array);
			return (NULL);
		}
		ft_memset(map->array[i], '.', map_size);
		i++;
	}
	return (map);
}

size_t	count_pieces(t_piece *piecelist)
{
	size_t	count;

	count = 0;
	while (piecelist)
	{
		piecelist = piecelist->next;
		count++;
	}
	return (count);
}

void	print_map(t_map *map, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_putstr(map->array[i]);
		ft_putchar('\n');
		i++;
	}
}

void	free_map(t_map *map, int map_size)
{
	int	i;

	i = 0;
	while (i < map_size)
	{
		ft_memdel((void **)&(map->array[i]));
		i++;
	}
	ft_memdel((void **)&(map->array));
	ft_memdel((void **)&map);
}
