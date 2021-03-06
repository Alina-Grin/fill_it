/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szeftyr <szeftyr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 18:16:43 by rtory             #+#    #+#             */
/*   Updated: 2019/11/24 15:45:52 by szeftyr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		overlap(t_map *map, t_piece *piece)
{
	int i;
	int x;
	int y;

	i = 0;
	x = 0;
	y = 0;
	x = piece->blockcoords[i] + piece->x_offset;
	y = piece->blockcoords[i + 1] + piece->y_offset;
	while (i <= 6 && map->array[y][x] == '.')
	{
		i += 2;
		x = piece->blockcoords[i] + piece->x_offset;
		y = piece->blockcoords[i + 1] + piece->y_offset;
	}
	return (i != 8);
}

int		in_border(t_piece *piece, int map_size, char axis)
{
	if (axis == 'y')
		return (piece->blockcoords[1] + piece->y_offset < map_size &&
				piece->blockcoords[3] + piece->y_offset < map_size &&
				piece->blockcoords[5] + piece->y_offset < map_size &&
				piece->blockcoords[7] + piece->y_offset < map_size);
	else
		return (piece->blockcoords[0] + piece->x_offset < map_size &&
				piece->blockcoords[2] + piece->x_offset < map_size &&
				piece->blockcoords[4] + piece->x_offset < map_size &&
				piece->blockcoords[6] + piece->x_offset < map_size);
}

void	place(t_piece *piece, t_map *map, char letter)
{
	int i;
	int x;
	int y;

	i = 0;
	x = 0;
	y = 0;
	while (i <= 6)
	{
		x = piece->blockcoords[i] + piece->x_offset;
		y = piece->blockcoords[i + 1] + piece->y_offset;
		map->array[y][x] = letter;
		i += 2;
	}
}

int		solve_map(t_map *map, t_piece *piece, int map_size)
{
	if (!piece)
		return (1);
	piece->x_offset = 0;
	piece->y_offset = 0;
	while (in_border(piece, map_size, 'y'))
	{
		while (in_border(piece, map_size, 'x'))
		{
			if (!overlap(map, piece))
			{
				place(piece, map, piece->pieceletter);
				if (solve_map(map, piece->next, map_size))
					return (1);
				else
					place(piece, map, '.');
			}
			piece->x_offset++;
		}
		piece->x_offset = 0;
		piece->y_offset++;
	}
	return (0);
}

void	solve(t_piece *piecelist)
{
	t_map	*map;
	int		map_size;

	map_size = round_up_sqr(count_pieces(piecelist) * 4);
	map = new_map(map_size);
	while (!solve_map(map, piecelist, map_size))
	{
		free_map(map, map_size);
		map_size++;
		map = new_map(map_size);
	}
	print_map(map, map_size);
	free_map(map, map_size);
}
