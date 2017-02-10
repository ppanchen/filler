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

char	**parse_map(t_config *conf)
{

}

int 	main(int ac, char **av)
{
	char		*file;
	int			i;
	int 		j;
	int			fd;
	t_config	*conf;

	fd = open("file.txt", O_CREAT | O_RDWR);
	conf	= (t_config *)malloc(sizeof(t_config));
	get_next_line(0, &file);
	conf->pnum = file[10] - '0';
	conf->symb = (conf->pnum == 1) ? 'O' : 'X';
	while (get_next_line(0, &file))
	{
		ft_putstr_fd(file, fd);
		ft_putchar_fd('\n', fd,  -1);
		i = 0;
		while (ft_isdigit(file[i]))
			i++;
		file += i;
		conf->raw = ft_atoi(file);
		file += ft_numlen(conf->raw);
		conf->col = ft_atoi(file);
		conf->map = parse_map(conf);
	}
	close(fd);
	return (0);
}
