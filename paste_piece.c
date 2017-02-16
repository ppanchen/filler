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

int			paste_piece(t_config conf)
{
	int i;
	int coor[2];

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
	return (i);
}
