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
# include <fcntl.h>   //must be removed

typedef	struct 	s_config
{
	int 		col;
	int 		raw;
	int 		pnum;
	char 		symb;
	char 		**map;
	int 		p_col;
	int 		p_raw;
	char 		*piece;
}				t_config;


#endif