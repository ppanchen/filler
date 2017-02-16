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

int 		is_blocked(t_config conf)
{
	int		i;
	int		j;

	i = -1;

}

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

int 		find_enemy(t_config	conf)
{
	int 	coord[4];
	char    en_char;
	int 	ret;

	en_char	= conf.symb == 'O' ? 'X' : 'O';
	find_first_char(&coord[0], &coord[1], conf.symb, conf);
	find_first_char(&coord[2], &coord[3], en_char, conf);
	coord[0] -= coord[2];
	coord[1] -= coord[3];
	(coord[0] > 0 && coord[1] > 0) && (ret = 2);
	(coord[0] < 0 && coord[1] > 0) && (ret = 1);
	(coord[0] > 0 && coord[1] < 0) && (ret = 3);
	(coord[0] < 0 && coord[1] < 0) && (ret = 4);
	(coord[0] == 0 && coord[1] > 0) && (ret = 12);
	(coord[0] == 0 && coord[1] < 0) && (ret = 34);
	(coord[0] > 0 && coord[1] == 0) && (ret = 23);
	(coord[0] < 0 && coord[1] == 0) && (ret = 14);
	return (ret);
}

void		define_tact(t_tactic **tact, t_config conf)
{
	if (!(*tact))
	{
		*tact = (t_tactic *)malloc(sizeof(t_tactic));
		(*tact)->en_pos = find_enemy(conf);
	}

}

int			paste_piece(t_config conf)
{
	int				i;
	int				coor[2];
	static t_tactic	*tact = NULL;

	define_tact(&tact, conf);
	coor[0] = -1;
	while (++coor[0] < conf.raw)
	{
		coor[1] = -1;
		while (++coor[1] < conf.col)
		{
			if ((i = try_paste(conf, coor)))
				break ;
		}
		if (i == 1)
			break ;
	}
	if (i == 1)
		ft_printf("%i %i\n", coor[0], coor[1]);
	else
		ft_printf("0 0\n");
	return (i);
}

/*
**	coor[0] = -1;
**	while (++coor[0] < conf.raw)
**	{
**		coor[1] = -1;
**		while (++coor[1] < conf.col)
**		{
**			if ((i = try_paste(conf, coor)))
**				break ;
**		}
**		if (i == 1)
**			break ;
**	}
*/