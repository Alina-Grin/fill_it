/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtory <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 18:16:32 by rtory             #+#    #+#             */
/*   Updated: 2019/11/12 13:44:42 by rtory            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		free_piecelist(t_piece *list)
{
	t_piece *tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
}

t_piece		*align(t_piece *piece)
{
	while (piece->blockcoords[0] != 0 && \
			piece->blockcoords[2] != 0 && \
			piece->blockcoords[4] != 0 && \
			piece->blockcoords[6] != 0)
		shift_x(piece, -1);
	while (piece->blockcoords[1] != 0 && \
			piece->blockcoords[3] != 0 && \
			piece->blockcoords[5] != 0 && \
			piece->blockcoords[7] != 0)
		shift_y(piece, -1);
	return (piece);
}

t_piece		*makepiece(char *buf, char pieceletter)
{
	t_piece	*piece_ptr;
	int		x;
	int		y;
	int		i;

	i = 0;
	x = 0;
	y = 1;
	if (!(piece_ptr = (t_piece*)malloc(sizeof(t_piece))))
		return (NULL);
	while (i < 20)
	{
		if (buf[i] == '#')
		{
			piece_ptr->blockcoords[x] = (i >= 5) ? (i % 5) : i;
			piece_ptr->blockcoords[y] = i / 5;
			x += 2;
			y += 2;
		}
		i++;
	}
	piece_ptr->x_offset = 0;
	piece_ptr->y_offset = 0;
	piece_ptr->pieceletter = pieceletter;
	return (align(piece_ptr));
}

t_piece		*makelist(char *buf, int size)
{
	t_piece *current;
	t_piece *beginning;
	int		i;
	char	pieceletter;

	i = 0;
	pieceletter = 'A';
	while (i < size)
	{
		if (pieceletter == 'A')
		{
			beginning = makepiece(buf + i, pieceletter);
			current = beginning;
		}
		else
		{
			current->next = makepiece(buf + i, pieceletter);
			current = current->next;
		}
		pieceletter++;
		i += 21;
	}
	current->next = NULL;
	return (beginning);
}

t_piece		*parser(char *filename)
{
	char	buf[547];
	int		fd;
	int		bytecount;

	fd = open(filename, O_RDONLY);
	bytecount = read(fd, buf, 546);
	close(fd);
	buf[bytecount] = '\0';
	if (!valid(buf, bytecount))
		return (NULL);
	return (makelist(buf, bytecount));
}
