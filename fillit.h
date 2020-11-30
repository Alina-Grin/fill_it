/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szeftyr <szeftyr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 15:42:38 by rtory             #+#    #+#             */
/*   Updated: 2019/11/24 15:47:17 by szeftyr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct		s_piece
{
	int				blockcoords[8];
	char			pieceletter;
	int				x_offset;
	int				y_offset;
	struct s_piece	*next;
}					t_piece;

typedef struct		s_map
{
	char			**array;
}					t_map;

void				shift_x(t_piece *piece, int n);
void				shift_y(t_piece *piece, int n);
t_piece				*align(t_piece *piece);
t_piece				*makepiece(char *buf, char pieceletter);
t_piece				*makelist(char *buf, int size);
t_piece				*parser(char *filename);
int					count_char(char *buf);
int					count_neighbourhood(char *buf);
int					valid(char *buf, int size);
int					round_up_sqr(int num);
t_map				*new_map(int map_size);
size_t				count_pieces(t_piece *piecelist);
void				print_map(t_map *map, int size);
void				place(t_piece *piece, t_map *map, char letter);
void				solve(t_piece *piecelist);
int					in_border(t_piece *piece, int map_size, char axis);
void				free_piecelist(t_piece *list);
void				free_map(t_map *map, int map_size);
#endif
