/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 15:19:58 by ppanchen          #+#    #+#             */
/*   Updated: 2017/02/09 15:19:59 by ppanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "libft/libft.h"

/*
** next line must be removed
*/
# include <fcntl.h>

typedef	struct	s_config
{
	int			col;
	int			raw;
	int			pnum;
	char		symb;
	char		**map;
	int			p_col;
	int			p_raw;
	char		**piece;
}				t_config;
/*
** pos: 2|1
** 	   	-0-
**      3|4
** blocked: is enemy cut off other world
*/
typedef struct	s_tactic
{
	int 		en_pos;
	int			blocked;
}				t_tactic;

void			parse_map(t_config **conf);
void			parse_piece(t_config **conf);
int				paste_piece(t_config conf);
int				try_paste(t_config conf, int coor[]);
#endif
