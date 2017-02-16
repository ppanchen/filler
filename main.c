/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 15:10:49 by ppanchen          #+#    #+#             */
/*   Updated: 2017/02/09 15:10:51 by ppanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int 	main(int ac, char **av)
{

	int			i;
	int 		j;
	char 		*input;
	t_config	*conf;
	int 		res;

	conf = (t_config *)malloc(sizeof(t_config));
	get_next_line(0, &input);
	conf->pnum = input[10] - '0';
	conf->symb = (conf->pnum == 1) ? 'O' : 'X';
	res = 1;
	while (res != 0)
	{
		parse_map(&conf);
		parse_piece(&conf);
		res = paste_piece(*conf);
	}
	return (0);
}
