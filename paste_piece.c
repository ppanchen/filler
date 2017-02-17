/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paste_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 12:06:59 by ppanchen          #+#    #+#             */
/*   Updated: 2017/02/16 12:07:00 by ppanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

//int 		is_blocked(t_config conf)
//{
//	int		i;
//	int		j;
//
//	i = -1;
//
//}

//int 		find_enemy(t_config	conf)
//{
//	int 	coord[4];
//	char    en_char;
//	int 	ret;
//
//	en_char	= conf.symb == 'O' ? 'X' : 'O';
//	find_first_char(&coord[0], &coord[1], conf.symb, conf);
//	find_first_char(&coord[2], &coord[3], en_char, conf);
//	coord[0] -= coord[2];
//	coord[1] -= coord[3];
//	(coord[0] > 0 && coord[1] > 0) && (ret = 2);
//	(coord[0] < 0 && coord[1] > 0) && (ret = 1);
//	(coord[0] > 0 && coord[1] < 0) && (ret = 3);
//	(coord[0] < 0 && coord[1] < 0) && (ret = 4);
//	(coord[0] == 0 && coord[1] > 0) && (ret = 12);
//	(coord[0] == 0 && coord[1] < 0) && (ret = 34);
//	(coord[0] > 0 && coord[1] == 0) && (ret = 23);
//	(coord[0] < 0 && coord[1] == 0) && (ret = 14);
//	return (ret);
//}
//
//void		define_tact(t_tactic **tact, t_config conf)
//{
//	if (!(*tact))
//	{
//		*tact = (t_tactic *)malloc(sizeof(t_tactic));
//		(*tact)->en_pos = find_enemy(conf);
//	}
//
//}

void		find_first_char(int *x, int *y, char c, t_config conf)
{
	*y = -1;
	while (conf.map[++(*y)])
	{
		(*x) = -1;
		while (conf.map[++(*x)])
			if(conf.map[(*y)][(*x)] == c)
				break ;
		if(conf.map[(*y)][(*x)] == c)
			break ;
	}
}

int 		**fill_digit(int **map, t_config conf)
{
	int i;
	int j;
	int k;
	int last;


	k = 1000;
	last = -3;
	while (--k >= 0)
	{
		i = -1;
		while (conf.map[++i])
		{
			j = -1;
			while (conf.map[i][++j])
			{
				if (map[i][j] == last)
				{
					(i != 0 && map[i - 1][j] == -1) && (map[i - 1][j] = k);
					(j != 0 && map[i][j - 1] == -1) && (map[i][j - 1] = k);
					(i != conf.raw - 1 && map[i + 1][j] == -1) &&
							(map[i + 1][j] = k);
					(j != conf.col - 1 && map[i][j + 1] == -1) &&
							(map[i][j + 1] = k);
				}
			}
		}
		last = k;
	}
	return (map);
}

int 		**map_cpy(t_config conf)
{
	int	i;
	int j;
	int **map;

	map = (int **)malloc(sizeof(int *) * (conf.raw + 1));
	i = -1;
	while (conf.map[++i])
		map[i] = (int *)malloc(sizeof(int) * (conf.col + 1));
	map[i] = 0;
	i = -1;
	while (conf.map[++i])
	{
		j = -1;
		while (conf.map[i][++j])
		{
			if (conf.map[i][j] == '.')
				map[i][j] = -1;
			else if (conf.map[i][j] == conf.symb ||
					conf.map[i][j] == conf.symb + 32)
				map[i][j] = -2;
			else
				map[i][j] = -3;
		}
		map[i][j] = 0;
	}
	return (map);
}

/*
** int map: '-1' - empty
** 			'-2' - my dot
** 			'-3' - enemy dot;
*/

int 		count_weight(int coor[], int **map, t_config conf)
{
	int		result;
	int 	x;
	int 	y;

	result = 0;
	x = -1;
	while (conf.piece[++x])
	{
		y = -1;
		while (conf.piece[x][++y])
		{
			if (conf.piece[x][y] == '*')
				result += map[coor[0] + x][coor[1] + y];
		}
	}
	return (result);
}

int			paste_piece(t_config conf)
{
	int				i;
	t_coord			*c;
	int				**map;
	int 			coor[2];


	map = map_cpy(conf);
	map = fill_digit(map, conf);
	i = -1;
		while (map[++i])
		{
			int j  = -1;
			while (map[i][++j])
			{
				ft_putstr_fd("|", 3);
				ft_putnbr_fd(map[i][j], 3);
				ft_putstr_fd("|", 3);
			}
			ft_putstr_fd("\n", 3);
		}
	coor[0] = -1;
	c = NULL;
	while (++coor[0] < conf.raw)
	{
		coor[1] = -1;
		while (++coor[1] < conf.col)
			if (try_paste(conf, coor))
				c = lst_add(coor, count_weight(coor, map, conf), c);
	}
	c = find_bigger(c);
	if (!c)
	{
		ft_printf("0 0\n");
		return (0);
	}
	ft_printf("%i %i\n", c->x, c->y);
	return (1);
}


//	int i = -1;
//	while (map[++i])
//	{
//		int j  = -1;
//		while (map[i][++j])
//		{
//			ft_putstr_fd("|", 3);
//			ft_putnbr_fd(map[i][j], 3);
//			ft_putstr_fd("|", 3);
//		}
//		ft_putstr_fd("\n", 3);
//	}
//
//	coor[0] = -1;
//	while (++coor[0] < conf.raw)
//	{
//		coor[1] = -1;
//		while (++coor[1] < conf.col)
//		{
//			if ((i = try_paste(conf, coor)))
//				break ;
//		}
//		if (i == 1)
//			break ;
//	}
//