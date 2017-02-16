/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 11:10:20 by ppanchen          #+#    #+#             */
/*   Updated: 2017/02/16 11:10:21 by ppanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		parse_piece(t_config ** conf)
{
	char		*input;
	int 		i;

	get_next_line(0, &input);
	ft_putendl_fd(input, 3);
	i = 0;
	while(ft_isdigit(input[i]) == 0)
		i++;
	(*conf)->p_raw = ft_atoi(input + i);
	ft_putnbr_fd((*conf)->p_raw, 3);
	ft_putstr_fd("\n",3);
	i += ft_numlen((*conf)->p_raw);
	(*conf)->p_col = ft_atoi(input + i);
	ft_putnbr_fd((*conf)->p_col, 3);
	ft_putstr_fd("\n",3);
	i = 0;
	(*conf)->piece = (char **)malloc(sizeof(char *) * ((*conf)->p_raw + 1));
	while(i < (*conf)->p_raw)
	{
		get_next_line(0, &input);
		(*conf)->piece[i] = input;
		ft_putendl_fd((*conf)->piece[i], 3);
		i++;
	}
	(*conf)->piece[i] = 0;
}

void		parse_map(t_config **conf)
{
	char		*input;
	int 		fd;
	int 		i;

	fd = open("file.txt", O_CREAT | O_RDWR);
	get_next_line(0, &input);
	ft_putendl_fd(input, fd);
	i = 0;
	while(ft_isdigit(input[i]) == 0)
		i++;
	(*conf)->raw = ft_atoi(input + i);
	ft_putnbr_fd((*conf)->raw, fd);
	ft_putstr_fd("\n",fd);
	i += ft_numlen((*conf)->raw);
	(*conf)->col = ft_atoi(input + i);
	ft_putnbr_fd((*conf)->col, fd);
	ft_putstr_fd("\n",fd);
	i = 0;
	get_next_line(0, &input);
	(*conf)->map = (char **)malloc(sizeof(char *) * ((*conf)->raw + 1));
	while(i < (*conf)->raw)
	{
		get_next_line(0, &input);
		(*conf)->map[i] = input + 4;
		ft_putendl_fd((*conf)->map[i], fd);
		i++;
	}
	(*conf)->map[i] = 0;
}
