/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 13:24:09 by ppanchen          #+#    #+#             */
/*   Updated: 2017/02/16 13:24:10 by ppanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		try_paste(t_config conf, int coor[])
{
	int i;
	int j;
	int flag;

	flag = 0;
	if (conf.raw < conf.p_raw + coor[0] || conf.col < conf.p_col + coor[1])
		return (0);
	i = -1;
	while (++i < conf.p_raw)
	{
		j = -1;
		while (++j < conf.p_col)
		{
			if (conf.map[coor[0] + i][coor[1] + j] != '.' &&
					conf.piece[i][j] != '.')
			{
				if (conf.map[coor[0] + i][coor[1] + j] != conf.symb
					&& conf.map[coor[0] + i][coor[1] + j] != conf.symb + 32)
					return (0);
				flag++;
			}
		}
	}
	return (flag == 1 ? 1 : 0);
}
