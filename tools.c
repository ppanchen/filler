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

t_coord	*lst_add(int coor[], int weight, t_coord *start)
{
	t_coord	*tmp;

	if (!start)
	{
		start = (t_coord *)malloc(sizeof(t_coord));
		start->x = coor[0];
		start->y = coor[1];
		start->weight = weight;
		start->next = NULL;
	}
	else
	{
		tmp = start;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = (t_coord *)malloc(sizeof(t_coord));
		tmp = tmp->next;
		tmp->x = coor[0];
		tmp->y = coor[1];
		tmp->weight = weight;
		tmp->next = NULL;
	}
	return (start);
}

t_coord	*find_bigger(t_coord *start)
{
	t_coord	*tmp;
	t_coord	*res;

	if (!start)
		return (start);
	tmp = start;
	res = start;
	while (tmp)
	{
		if (tmp->weight > res->weight)
			res = tmp;
		tmp = tmp->next;
	}
	return (res);
}
